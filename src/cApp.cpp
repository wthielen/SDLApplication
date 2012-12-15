#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 600
#define DISPLAY_HEIGHT 600

cApp::cApp() {
    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    return true;
}

void cApp::loop() {
}

void cApp::render() {
}

void cApp::cleanup() {
    cActivity::cleanup();
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
