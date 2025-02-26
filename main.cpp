#include "UI/UI/UI.h"
#include "Domain/Cafe/Cafe.h"
#include "Domain/Menu/Menu.h"
#include "Data/Data.h"
#include "UI/Logger/Logger.h"

int main() {
    Menu menu;
    Data data;
    Cafe cafe(&menu, &data);
    Logger logger;
    UI ui(&cafe, &logger);
    ui.run();
    return 0;
}