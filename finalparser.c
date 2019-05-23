#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int count = 0;

typedef enum _TOKEN_TYPE {
    TOKEN_UNDEFINED,
    TOKEN_OBJECT,
    TOKEN_ARRAY,
    TOKEN_STRING,
    TOKEN_PRIMITIVE,
    TOKEN_NUMBER
} TOKEN_TYPE;

typedef struct _TOKEN {
    TOKEN_TYPE type;
    int tokensize;
    int start;
    int end;
    int size;
    union {
        char *string;
        double number;
    };
} TOKEN;

#define TOKEN_COUNT 26

typedef struct _JSON {
    TOKEN tokens[TOKEN_COUNT];
} JSON;

char *readFile(char *filename, int *readSize)
{
    FILE *fp = fopen(filename, "rb");
    if(fp==NULL)
        return NULL;
    
    int size;
    char *buffer;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = malloc(size + 1);
    memset(buffer, 0, size+1);

    if(fread(buffer, size, 1, fp)<1){
        *readSize = 0;
        free(buffer);
        fclose(fp);
        return NULL;
    }

    *readSize = size;

    fclose(fp);

    return buffer;
}

void parseJSON(char *doc, int size, JSON *json)
{
    int tokenIndex = 0;
    int pos = 0;

    if(doc[pos] != '{')
        return;
    pos++;
    int temp_pos = pos-1;

    while(pos<size)
    {
        switch(doc[pos])
        {
            case ',':
            {
                temp_pos-=2;
            }
            break;
            case '{':
            {
                count++;
                int K = tokenIndex;
                char *begin = doc + pos;
                char *end = strchr(begin, '}');
                int stringLength = end - begin + 1;
                char *check = doc + pos + 1;
                int tsize = 0;
                for(int k=0; k<=stringLength+1; k++){
                    int tsize = 0;
                    if(check[stringLength+1]==':'){
                        tsize++;
                        
                        json->tokens[tokenIndex].tokensize = tsize;
                    }
                                    
                }
                //herere
                int k=0;
                while(check[k]!='}'){
                    if(check[k]=='"'&check[k+1]==':')
                        tsize++;
                    k++;
                }

                json->tokens[tokenIndex].tokensize=tsize;
                //herere

                json->tokens[tokenIndex].start = temp_pos;
                json->tokens[tokenIndex].end = json->tokens[tokenIndex].start + stringLength;
                json->tokens[tokenIndex].string = malloc(stringLength+1);
                memset(json->tokens[tokenIndex].string, 0, stringLength + 1);
                memcpy(json->tokens[tokenIndex].string, begin, stringLength);
                json->tokens[tokenIndex].type = TOKEN_OBJECT;
                tokenIndex++;
            }
            break;

            case '[':
            {
                count++;
                int K = tokenIndex;
                char *begin = doc + pos;
                char *end = strchr(begin, ']');
                int stringLength = end - begin + 1;
                char *check = doc + pos + 1;
                int tsize = 0;
                for(int k=0; k<=stringLength+1; k++){
                    int tsize = 0;
                    if(check[stringLength+1]==':'){
                        tsize++;
                       
                        json->tokens[tokenIndex].tokensize = tsize;
                    }
                   
                }

                int k=0;
                while(check[k]!='}'){
                    if(check[k]=='"'&check[k+1]==':')
                        tsize++;
                    k++;
                }

                json->tokens[tokenIndex].tokensize=tsize;

                json->tokens[tokenIndex].start = temp_pos;
                json->tokens[tokenIndex].end = json->tokens[tokenIndex].start + stringLength;
                json->tokens[tokenIndex].string = malloc(stringLength+1);
                memset(json->tokens[tokenIndex].string, 0, stringLength + 1);
                memcpy(json->tokens[tokenIndex].string, begin, stringLength);
                json->tokens[tokenIndex].type = TOKEN_ARRAY;
                tokenIndex++;
            }
            break;

            case '"':
            {
                count++;
                char *begin = doc + pos + 1;
                char *end = strchr(begin, '"');
                if(end==NULL)
                    break;
                
                int stringLength = end-begin;

                //here
                char *check = doc + pos + 1;
                int tsize = 0;
                for(int k=0; k<=stringLength+1; k++){
                    int tsize = 0;
                    if(check[stringLength+1]==':'){
                        tsize++;
                    
                        json->tokens[tokenIndex].tokensize = tsize;
                    }
                    else
                        json->tokens[tokenIndex].tokensize = 0;
                    
                }
                        

                json->tokens[tokenIndex].type = TOKEN_STRING;
                json->tokens[tokenIndex].string = malloc(stringLength + 1);
                json->tokens[tokenIndex].start = temp_pos;
                json->tokens[tokenIndex].end = json->tokens[tokenIndex].start + stringLength;

                memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

                memcpy(json->tokens[tokenIndex].string, begin, stringLength);

                tokenIndex++;
                
                pos = pos + stringLength + 1;
                temp_pos = temp_pos + stringLength+1;
            }
            break;


            case '0': case '1': case'2': case'3': case '4' : case '5' : case '6' : case '7' : case '8' : case '9' : case '-' :
            {
                count++;
                char *begin = doc + pos;
                char *end;
                char *buffer;

                end = strchr(doc + pos, ',');
                if(end==NULL)
                {
                    end = strchr(doc + pos, '}');
                    if(end==NULL)
                        break;
                }
                int stringLength = end - begin;

                //here
                char *check = doc + pos + 1;
                int tsize = 0;
                for(int k=0; k<=stringLength+1; k++){
                    int tsize = 0;
                    if(check[stringLength+1]==':'){
                        tsize++;
                        json->tokens[tokenIndex].tokensize = tsize;
                    }
                    else
                        json->tokens[tokenIndex].tokensize = 0;
                    }

                buffer = malloc(stringLength + 1);
                memset(buffer, 0, stringLength + 1);
                memcpy(buffer, begin, stringLength);

                json->tokens[tokenIndex].type = TOKEN_NUMBER;
                json->tokens[tokenIndex].number = atof(buffer);
                json->tokens[tokenIndex].start = temp_pos;
                json->tokens[tokenIndex].end = json->tokens[tokenIndex].start + stringLength;
                free(buffer);

                tokenIndex++;

                pos = pos+stringLength + 1;
                temp_pos = temp_pos + stringLength+1;
            }
            break;
        }
        pos++;
        temp_pos++;
    }
}

void freeJSON(JSON *json)
{
    for(int i=0; i<TOKEN_COUNT; i++)
    {
        if(json->tokens[i].type == TOKEN_STRING)
            free(json->tokens[i].string);
    }
}

int main(int argc, char **argv)
{
    int size;
    
    char *doc = readFile(argv[1], &size);
    if(doc==NULL)
        return -1;
    

    JSON json = { 0, };
    
    parseJSON(doc, size, &json);
    
    printf("***** ALL Tokens *******\n");

    for(int i=0; i<count; i++)
    {
        if(json.tokens[i].type==0)
            printf("[%2d] %s (size=%d, %d~%d , JSMN_UNDEFINED)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
        else if(json.tokens[i].type==1)
            printf("[%2d] %s (size=%d, %d~%d , JSMN_OBJECT)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
        else if(json.tokens[i].type==2)
            printf("[%2d] %s (size=%d, %d~%d , JSMN_ARRAY)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
        else if(json.tokens[i].type==3)
            printf("[%2d] %s (size=%d, %d~%d, JSMN_STRING)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
        else if(json.tokens[i].type==4)
            printf("[%2d] %s (size=%d, %d~%d, JSMN_PRIMITIVE)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
        else
            printf("[%2d] %s (size=%d, %d~%d, JSMN_NUMBER)\n", i+1, json.tokens[i].string, json.tokens[i].tokensize, json.tokens[i].start, json.tokens[i].end);
    }
    
    freeJSON(&json);
    free(doc);
    return 0;
}