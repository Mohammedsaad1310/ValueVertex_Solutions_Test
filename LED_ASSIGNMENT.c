#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Macros indicating LED Status
#define OFF  0              
#define ON   1

//Macros indicating LED Brightness Level
#define MINIMUM_BRIGHTNESS 0
#define MAXIMUM_BRIGHTNESS 255

//Macros indicating LED Color
#define NO_COLOR -1
#define RED    0x00FF0000
#define GREEN  0x0000FF00
#define BLUE   0x000000FF

// Structure representing individual LED settings
typedef struct 
{
    uint8_t state;
    uint8_t brightness;
    uint32_t color;
} LEDSettings;

// Structure representing a group of LEDs
typedef struct
{
    LEDSettings singleLED;
    uint8_t groupState;
    uint8_t groupBrightness;
}LEDGroup;

// Function to initialize LED group with default values
void initLEDGroup(LEDGroup *group) 
{
    group->singleLED.state = OFF;
    group->singleLED.brightness = MINIMUM_BRIGHTNESS;
    group->singleLED.color = NO_COLOR;
    group->groupState = OFF;
    group->groupBrightness = MINIMUM_BRIGHTNESS;
}

// Function to update both individual and group LED settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness,
                            uint8_t state, uint8_t brightness, uint32_t color) {
    // Update individual LED settings
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;

    // Update group settings
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
}

// Function to print the current status of the LED group
void displayLEDGroupStatus(const LEDGroup *group)
{
 
    printf("Individual LED Status:\n");
    if (group->singleLED.state == ON)
    {
        printf("State: ON\n");
    }
    else
    {
         printf("State: OFF\n");
        
    }
    if(group->singleLED.brightness == MINIMUM_BRIGHTNESS)
    {
         printf("Brightness: Minimum brightness\n");
    }
    else if(group->singleLED.brightness == MAXIMUM_BRIGHTNESS)
    {
        printf("Brightness: Maximun brightness\n");
    }
    else 
    {
        if ((group->singleLED.brightness < MAXIMUM_BRIGHTNESS )|| (group->singleLED.brightness >MINIMUM_BRIGHTNESS ))
        {
            printf("Brightness: moderate brightness\n");
        }
    }
    if (group->singleLED.color == RED )
    {
          printf("Color: RED\n");
    }
    else if (group->singleLED.color == GREEN )
    {
     printf("Color: GREEN\n");
    }
    else if (group->singleLED.color == BLUE )
    {
         printf("Color: BLUE\n");
    }
    else
    {
        printf("Color: NO_Color\n");
    }

    printf("Group Status:\n");
    switch (group->groupState)
    {
        case ON : printf("State: ON\n");
                  break;
        case OFF :printf("State: OFF\n");  
                  break;
        
    }
    switch (group->groupBrightness)
    {
        case MINIMUM_BRIGHTNESS: printf("Group Brightness: Minimum brightness\n");
                                 break;
        case MAXIMUM_BRIGHTNESS: printf("Group Brightness: Maximum brightness\n");
                                 break;
        default : printf("Group Brightness: moderate brightness");    
        
    }
    
}

int main() 
{
    // Allocate memory for LEDGroup
    LEDGroup *group = malloc(sizeof(LEDGroup)); 
    if (group == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // Demonstrating the reruired function calls
    initLEDGroup(group);
    updateLEDGroupSettings(group, 1, 255, ON, 0, RED);
    displayLEDGroupStatus(group);
    
    // Free allocated memory
    free(group); 
    return 0;
}