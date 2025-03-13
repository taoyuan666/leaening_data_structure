#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct line {
    int num;
    struct line *next;
};

struct word {
    char keyw[20];
    int times;
    struct line *post;
};

void add(struct word *words, int num_of_word, char *word, int num_of_line);
void print(struct word *words, int num_of_word, char *output_file);

int main() {
    char filename[50], output_file[50];
    int num_of_word, num_of_line = 1;
    struct word words[100];

    char *keywords[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","inline","int","long","register","restrict","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    num_of_word = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_of_word; i++) {
        strncpy(words[i].keyw, keywords[i], sizeof(words[i].keyw) - 1);
        words[i].keyw[sizeof(words[i].keyw) - 1] = '\0';
        words[i].times = 0;
        words[i].post = NULL;
    }

    printf("Enter the file path: ");
    scanf("%s", filename);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    FILE *openfile = fopen(filename, "r");
    if (openfile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char line[200];
    int line_final = 0;
    char ch;
    while ((ch = fgetc(openfile)) != EOF) {
        if (ch == '\n') {
            line[line_final] = '\0';

            char *token = strtok(line, " ,.;\n");
            while (token != NULL) {
                for (int i = 0; token[i]; i++) {
                    token[i] = tolower(token[i]);
                }
                add(words, num_of_word, token, num_of_line);
                token = strtok(NULL, " ,.;\n");
            }
            num_of_line++;
            line_final = 0;
        } else {
            if (line_final < sizeof(line) - 1) {
                line[line_final++] = ch;
            }
        }
    }
    fclose(openfile);

    print(words, num_of_word, output_file);
    return 0;
}

void add(struct word *words, int num_of_word, char *word, int num_of_line) {
    for (int i = 0; i < num_of_word; i++) {
        if (strcmp(words[i].keyw, word) == 0) {
            words[i].times++;
            struct line *new_node = (struct line *)malloc(sizeof(struct line));
            new_node->num = num_of_line;
            new_node->next = words[i].post;
            words[i].post = new_node;
            break;
        }
    }
}

void print(struct word *words, int num_of_word, char *output_file) {
    FILE *openfile = fopen(output_file, "w");
    if (openfile == NULL) {
        perror("Error opening output file");
        return;
    }
    fprintf(openfile,"word             times            line\n");
    for (int i = 0; i < num_of_word; i++) {
        struct line *p = words[i].post;
        fprintf(openfile, "%s           %d  ", words[i].keyw, words[i].times);
        while (p != NULL) {
        fprintf(openfile, "   %d",p->num);
            p = p->next;
        }
        fprintf(openfile, "\n");
    }
    fclose(openfile);
    printf("Results written to: %s\n", output_file);
}
//       /Users/ty/Desktop/a.txt