#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <deque>
#include <string>

/*
	逆波兰表达式是一种把运算符前置的算术表达式
	如：2+3 的逆波兰表示法为 + 2 3 
	如：(2+3)*4 的逆波兰表示法为 x + 2 3 4
	输入：x + 11.0 12.0 + 24.0 35.0
	输出：1357.0
*/

using namespace std;


void log_array(deque<string> s){
    printf("array: ");
    for(int i=0; i<s.size(); i++){
        printf("%s",s[i].c_str());
    }
    printf("\n");
    
}

double notation(deque<string>& s)
{
    static int round = 0;
    printf("---\nround: %d\n",round);
    log_array(s);
    string token = s.front();
    printf("read token: %s\n",token.c_str());
    s.pop_front();
    log_array(s);
     round++;
    if (token == "+") 
    {
        return notation(s) + notation(s);
    }
    else if (token == "-")
    {
        return notation(s) - notation(s);
    }
    else if (token == "x")
    {
        return notation(s) * notation(s);
    }
    else if (token == "/")
    {
        return notation(s) / notation(s);
    }
    else
    {
        return stof(token);
    }
   
}

int main()
{
    deque<string> s;
    char input[] = "x + 11.0 12.0 + 24.0 35.0";
    printf("Parsing the input string: %s\n", input);
    //tokenize;
    char *token = strtok(input, " ");
    while (token)
    {
        printf("extract token: %s\n",token);
        s.push_back(string(token));
        token = strtok(NULL, " ");
    }
    printf("\n");
    
    double value = notation(s);
    printf("\nresult: %.2f\n",value);
    return 0;
}