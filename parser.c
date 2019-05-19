#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef enum {
	UNDEFINED = 0,
       	OBJECT = 1, 
	ARRAY = 2, 
	STRING = 3, 
	PRIMITIVE = 4
} jsmntype_t;

typedef struct {
    jsmntype_t type;
    char *string;
    double number;

    bool isArray;
    int start;
    int end;
    int size;
} jsmntok_t;

#define TOKEN_COUNT 21

typedef struct _JSON {
    jsmntok_t tokens[TOKEN_COUNT];
} JSON;

char *readFile(char *filename, int *readSize)
{
    FILE *fp = fopen(filename, "rb");
    if (fp==NULL)
        return NULL;

    int size;
    char *buffer;
    char data[size+1];

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = malloc(size+1);
    memset(buffer, 0, size+1);
    
    if(fread(buffer, size, 1, fp)<1)
    {
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
        return ;
    
    pos++;

    while (pos < size)
    {
        switch (doc[pos])
        {
            case '"':
            {
                char *begin = doc + pos + 1;
                char *end = strchr(begin, '"');
                if(end==NULL)
                    break;
                
                int stringLength = end - begin;

                json->tokens[tokenIndex].type = 3;
                json->tokens[tokenIndex].string, malloc(stringLength + 1);
                memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

                memcpy(json->tokens[tokenIndex].string, begin, stringLength);
		
                tokenIndex++;

                pos = pos + stringLength + 1;
            }
            break;
	    case '[':
	    {
	       pos++;

	       while (doc[pos] != ']')
		 {
		    if(doc[pos] == '"')
		    {
			char *begin = doc + pos + 1;
			char *end = strchr(begin, '"');
			if(end == NULL)
			   break;
			int stringLength = end - begin;

			json->tokens[tokenIndex].type = 2;
			json->tokens[tokenIndex].string = malloc(stringLength +1);
			json->tokens[tokenIndex].isArray = true;
			memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

			memcpy(json->tokens[tokenIndex].string, begin, stringLength);

			tokenIndex++;

			pos = pos + stringLength + 1;
		    }
		    pos++;
		 }
	    }
	    break;
	}
        pos++;     
    }
}

void freeJSON(JSON *json)
{
    for (int i=0; i<TOKEN_COUNT; i++)
    {
        if(json->tokens[i].type == 2)
            free(json->tokens[i].string);
	else if(json->tokens[i].type == 3)
            free(json->tokens[i].string);
    }
}

int main(){
    int size;
    char filename[20];
    scanf("%s", filename);
    char *doc = readFile(filename, &size);

    if (doc==NULL)
        return -1;
    
    JSON json = { 0, };

    parseJSON(doc, size, &json);

    printf("***** All Tokens *******\n");
    for(int i=0; i<TOKEN_COUNT ; i++)
    {
	   printf("[% d] %s (size=%d, %d~%d, JSMN_STRING)\n", i+1, json.tokens[i].string, json.tokens[i].size, json.tokens[i].start, json.tokens[i].end);
    }

    freeJSON(&json);

    free(doc);

    return 0;
}
