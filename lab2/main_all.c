#include <stdio.h>

void displayMenu();
int addGuest();
void displayGuest(int menu);

int main(){
    displayMenu();
    displayGuest(addGuest());
    return 0;
}

void displayMenu(){
    printf("***********************\n");
    printf("1. Pizza : 20000\n");
    printf("2. Spaghetti : 12000\n");
    printf("***********************\n\n");
};


int addGuest(){
    int menu; 
    printf("원하는 메뉴는? : ");
    scanf("%d", &menu);
    return menu;
}


void displayGuest(int menu){
    if(menu == 1) printf("Pizza\n");
    else printf("Spaghetti\n");
};