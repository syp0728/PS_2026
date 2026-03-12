#include <stdio.h>
#include "guest.h"
#include "menu.h"

int main(){
    displayMenu();
    displayGuest(addGuest());
    return 0;
}
