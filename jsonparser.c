#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TOKEN_COUNT 1024

//±žÁ¶ÃŒ Œ±Ÿð (Token ÅžÀÔ, ÅäÅ« žâ¹ö, ÅäÅ« ¹è¿­)
typedef enum {
   TOKEN_UNDEFINED = 0,
   TOKEN_OBJECT = 1,
   TOKEN_ARRAY = 2,
   TOKEN_STRING = 3,
   TOKEN_PRIMITIVE = 4

} TOKEN_TYPE;

typedef struct {
   TOKEN_TYPE type;
   int start;
   int end;
   int size;
   char *string;
} TOKEN;

typedef struct _JSON {
   TOKEN tokens[TOKEN_COUNT];
} JSON;

char *readFile(char*, int*);
void arrayParse(char*, JSON*, int*, int*);
void objectParse(char*, JSON*, int*, int*);
void jsonParse(char*, int, JSON*, int*);
void freeJson(JSON*, int);

//JSON ÆÄÀÏ ÀÐŸî¿À±â
char *readFile(char *filename, int *readSize) {
   FILE *fp = fopen(filename, "r");

   if (fp == NULL) {
      printf("Wrong Filename\n");
      return NULL;
   }
   int size;
   char *buffer;
   
   // ÆÄÀÏÀÇ ž¶Áöž·ºÎºÐÀž·Î °¡Œ­ »çÀÌÁî check ÈÄ ÆÄÀÏ Ã³ÀœÀž·Î µ¹ŸÆ°¡±â
   fseek(fp, 0, SEEK_END);   
   size = ftell(fp);
   fseek(fp, 0, SEEK_SET);

   // buffer žÞžðž® ÇÒŽç, ÃÊ±âÈ­ ÈÄ¿¡ µ¥ÀÌÅÍ ÀúÀå
   buffer = (char *)malloc(size + 1);
   memset(buffer, 0, size + 1);

   if (fread(buffer, 1, size, fp) < 1) {
      *readSize = 0;
      free(buffer);
      fclose(fp);
      return NULL;
   }

   *readSize = size;

   fclose(fp);

   return buffer;
}
// Array ÆÄœÌ
void arrayParse(char *doc, JSON *json, int *originPos, int *originIndex) {
   int pos = *originPos;
   int tokenIndex = *originIndex;
   int start;
   int end;

   // ArrayÅäÅ« indexÀúÀå 
   int arrayIndex = tokenIndex;
   json->tokens[tokenIndex].type = TOKEN_ARRAY;
   
   tokenIndex++;
   //ArrayÆÄœÌ¿¡Œ­ posŽÂ '['¿¡Œ­ œÃÀÛ, Ã³Àœ œÃÀÛ index ÀúÀå
   start = pos;
   json->tokens[arrayIndex].start = start;
   int arraySize = 0;
   
   // ']'žž³¯ ¶§±îÁö posÁõ°¡œÃÅ°žéŒ­ Array ¹üÀ§žŠ Ã£°í, ArrayŸÈ¿¡ contents ÆÄœÌ
   while (doc[pos] != ']') { 
      pos++;
      switch (doc[pos]) {
      //°¢ casežŠ žž³¯ ¶§ž¶ŽÙ arraySizežŠ Áõ°¡œÃÅ°žéŒ­ ÃÑ ArrayÀÇ »çÀÌÁî, °¢ ÅäÅ«ÀÇ ÅžÀÔ, ¹üÀ§žŠ checkÇÏ°í ÀúÀå 
      case '"':
         arraySize++;
         json->tokens[tokenIndex].type = TOKEN_STRING;
         //StringÆÄœÌ¿¡Œ­ posŽÂ '"' ŽÙÀœ¿¡Œ­ œÃÀÛ
         start = pos + 1;
         json->tokens[tokenIndex].start = start;
         
         // '"' žž³¯ ¶§±îÁö posÁõ°¡œÃÅ°žéŒ­ String ¹üÀ§ Ã£±â
         while (doc[pos + 1] != '"') {        
            pos++;
         }
         
         // StringÀº  '"'žŠ žž³ªžé '"'žŠ Æ÷ÇÔÇØŒ­ ¹üÀ§žŠ Ã£Àœ
         end = pos++;
         
         // end °ª ÀúÀåÈÄ size 0 ÃÊ±âÈ­ (°ªÀÌ±â ¶§¹®¿¡), žÞžðž® ÇÒŽçÈÄ µ¥ÀÌÅÍ ÀúÀå
         json->tokens[tokenIndex].end = end; 
         json->tokens[tokenIndex].size = 0; 
         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);
         tokenIndex++;
         break;
      // ŽÙœÃ ¹è¿­ÀÌ ³ª¿Àžé arraySize Áõ°¡ ÈÄ arrayParse ÇÔŒö ŽÙœÃ œÇÇà (Recursive)
      case '[':
         arraySize++;
         arrayParse(doc, json, &pos, &tokenIndex);
         break;
      // °ŽÃŒ°¡ ³ª¿Àžé arraySize Áõ°¡ ÈÄ objectParse ÇÔŒö œÇÇà
      case '{':
         arraySize++;
         objectParse(doc, json, &pos, &tokenIndex);
         break;

      //Primitive °ªÀÌ ³ª¿Àžé arraySize Áõ°¡ÈÄ index ŸÕ¿¡Œ­ Ÿð±ÞÇÑ ¹æœÄÀž·Î Œ³Á€
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
      case '+': case '-':
         
         arraySize++;
         json->tokens[tokenIndex].type = TOKEN_PRIMITIVE;
         start = pos;
         json->tokens[tokenIndex].start = start;
         
         // ',', '\n', ']' °ªÀ» žž³ª±â Àü±îÁö pos Áõ°¡œÃÄÑ Primitive ¹üÀ§ È®ÀÎ
         while (doc[pos + 1] != ',') { // ',' encounter ,
            if (doc[pos + 1] == '\n' || doc[pos + 1] == ']') break;
            else pos++;
         }
         //Primitive°ªÀº ',' or 'NULL' °ªÀÏ ¶§ ÁŸ·á
         end = pos++;
         
         //žÞžðž® ÇÒŽç, ÃÊ±âÈ­ ÈÄ µ¥ÀÌÅÍ ÀúÀå
         json->tokens[tokenIndex].end = end;
         json->tokens[tokenIndex].size = 0;
         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);
         if (doc[pos] != ']') pos++;
         tokenIndex++;
         break;

      default:
         break;
      }
   }
   end = pos++;
   
   //žÞžðž® ÇÒŽç, ÃÊ±âÈ­ ÈÄ µ¥ÀÌÅÍ ÀúÀå
   json->tokens[arrayIndex].end = end;
   json->tokens[arrayIndex].size = arraySize;
   json->tokens[arrayIndex].string = (char *)malloc(end - json->tokens[arrayIndex].start + 1);
   
   memset(json->tokens[arrayIndex].string, 0, end - json->tokens[arrayIndex].start + 1);
   memcpy(json->tokens[arrayIndex].string, doc + json->tokens[arrayIndex].start, end - json->tokens[arrayIndex].start);

   // ±âÁžÀÇ index¿Í pos¿¡ ÇöÀç index¿Í posžŠ µ¿±âÈ­ œÃÅŽ
   *originIndex = tokenIndex;
   *originPos = pos;
}
//ArrayParse ÇÔŒö¿Í °°Àº ÇüœÄ
void objectParse(char *doc, JSON *json, int *originPos, int *originIndex) {
   int pos = *originPos;
   int tokenIndex = *originIndex;
   int start, end;
   int objectIndex = tokenIndex;
   json->tokens[tokenIndex].type = TOKEN_OBJECT;
   tokenIndex++;                           
   start = pos;                             
   json->tokens[objectIndex].start = start;
   int objectSize = 0;

   while (doc[pos] != '}') { 
      pos++;
      switch (doc[pos]) {
      case '"':
         json->tokens[tokenIndex].type = TOKEN_STRING;
         start = pos + 1;                      
         pos++;
         json->tokens[tokenIndex].start = start;     
         while (doc[pos] != '"') {
            pos++;
         }
         end = pos;                         
         json->tokens[tokenIndex].end = end;  
         json->tokens[tokenIndex].size = 0; 
         while (doc[pos] != ':' && doc[pos] != '\n' && doc[pos] != ',' && doc[pos] != '}') {
            pos++;
         }
         if (doc[pos] == ':') {
            json->tokens[tokenIndex].size = 1;
         }
         else {
            objectSize++;
         }
         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);
         tokenIndex++; 
         break;

      case '[':
         objectSize++;
         arrayParse(doc, json, &pos, &tokenIndex);
         break;

      case '{':
         objectSize++;
         objectParse(doc, json, &pos, &tokenIndex);
         break;

       case '0': case '1': case '2': case '3': case '4':
       case '5': case '6': case '7': case '8': case '9':
       case '+': case '-':
         
          json->tokens[tokenIndex].type = TOKEN_PRIMITIVE;
         start = pos;
         json->tokens[tokenIndex].start = start;
         while (doc[pos + 1] != ',') { 
            if (doc[pos + 1] == '\n' || doc[pos + 1] == '}') {
               break;
            }
            else pos++;
         }
         objectSize++;
         end = pos++;
         json->tokens[tokenIndex].end = end;
         json->tokens[tokenIndex].size = 0;
         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);
         if (doc[pos] != '}') pos++;
         tokenIndex++;
         break;
      default:
         break;
      }
   }
   end = pos++;
   json->tokens[objectIndex].end = end;
   json->tokens[objectIndex].size = objectSize;
   json->tokens[objectIndex].string = (char *)malloc(end - json->tokens[objectIndex].start + 1);
   memset(json->tokens[objectIndex].string, 0, end - json->tokens[objectIndex].start + 1);
   memcpy(json->tokens[objectIndex].string, doc + json->tokens[objectIndex].start, end - json->tokens[objectIndex].start);

   *originIndex = tokenIndex;
   *originPos = pos;
}

void jsonParse(char *doc, int size, JSON *json, int *count) {
   // ÆÄœÌÇÏžéŒ­ checkÇÒ pos, start, end (ÅäÅ« ¹üÀ§), tokenIndex Œ±Ÿð
   int pos = 0;        
   int start, end;
   int tokenIndex = 0; 
   
   //positionÀÌ ÀüÃŒ sizeºžŽÙ ÀÛÀ» ¶§±îÁöžž œÇÇà
   while (pos < size) {
      
      //case º°·Î »óÈ² ºÎ¿© '{'ÀÏ ¶§ objectParseÇÔŒöžŠ œÇÇàÇÏ°í, '['ÀÏ ¶§ arrayParsežŠ œÇÇà ÀÌ¿Ü¿¡ °æ¿ìŽÂ jsonParse ÇÔŒö ŸÈ¿¡Œ­ ÆÄœÌ(ÆÄœÌ ¹æ¹ýÀº À§¿¡ Ÿð±ÞÇÑ ¹æ¹ý°ú µ¿ÀÏ
      switch (doc[pos]) {
      case '"':
         json->tokens[tokenIndex].type = TOKEN_STRING;
         start = pos + 1;
         pos++;                                   
         json->tokens[tokenIndex].start = start;    
         while (doc[pos] != '"') { 
            pos++;
         }

         end = pos;                       
         json->tokens[tokenIndex].end = end; 

         json->tokens[tokenIndex].size = 0;
         while (doc[pos] != ':' && doc[pos] != '\n' && doc[pos] != ',') {
            pos++;
         }
         if (doc[pos] != ':') { 
            json->tokens[tokenIndex].size = 1;
         }

         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);

         pos++;
         tokenIndex++;
         break;

      case '[':
         arrayParse(doc, json, &pos, &tokenIndex);
         break;

      case '{':
         objectParse(doc, json, &pos, &tokenIndex);
         break;

       case '0': case '1': case '2': case '3': case '4':
       case '5': case '6': case '7': case '8': case '9':
       case '+':case '-':
      
         json->tokens[tokenIndex].type = TOKEN_PRIMITIVE;
         start = pos;
         json->tokens[tokenIndex].start = start;
         while (doc[pos + 1] != ',') {
            if (doc[pos + 1] == '\n' || doc[pos + 1] == '}' || doc[pos + 1] == ']') break;
            else pos++;
         }
         end = pos++;
         
         json->tokens[tokenIndex].end = end;
         json->tokens[tokenIndex].size = 0;
         json->tokens[tokenIndex].string = (char *)malloc(end - start + 1);
         
         memset(json->tokens[tokenIndex].string, 0, end - start + 1);
         memcpy(json->tokens[tokenIndex].string, doc + start, end - start);
         
         if (doc[pos] != '}' && doc[pos] != ']') pos++;
         tokenIndex++;
         
         break;

      default:
         pos++;
      }
   }

   *count = tokenIndex; 
}
// žÞžðž® ÇØÁŠ
void freeJson(JSON *json, int count) {
   for (int i = 0; i < count; i++) {
      if (json->tokens[i].type == TOKEN_STRING)
         free(json->tokens[i].string);
   }
}

int main(int argc, char **argv) {
   int readSize = 0;
   char *doc = readFile(argv[1], &readSize);
   int count = 0; 

   if (doc == NULL) {
      printf("NULL");
      return -1;
   }
   
   // ±žÁ¶ÃŒ Œ±Ÿð
   JSON json = { 0 };
   //ÀÐŸî¿Â jsonÆÄÀÏ ÆÄœÌ
   jsonParse(doc, readSize, &json, &count);

   //µ¥ÀÌÅÍ Ãâ·Â
   char *stringType;
   for (int i = 0; i < count; i++) {
      if (json.tokens[i].type == 0)
         stringType = "TOKEN_UNDEFINED";
      else if (json.tokens[i].type == 1)
         stringType = "TOKEN_OBJECT";
      else if (json.tokens[i].type == 2)
         stringType = "TOKEN_ARRAY";
      else if (json.tokens[i].type == 3)
         stringType = "TOKEN_STRING";
      else
         stringType = "JSMN_PRIMITIVE";
      printf("[%d] %s (size = %d, %d~%d, %s) \n", i, json.tokens[i].string, json.tokens[i].size, json.tokens[i].start, json.tokens[i].end, stringType);
   }
   //žÞžðž® ÇØÁŠ
   freeJson(&json, count);

   return 0;
}