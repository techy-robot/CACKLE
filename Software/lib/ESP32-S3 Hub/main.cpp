#include "luos_engine.h"
#include node_config.h
#include simplefoc

// This is the main entry point for the ESP32-S3 Hub
int main(void)
{
    Luos_Init();
    while(1)
    {
        Luos_Loop();
    }
    return 0;
}