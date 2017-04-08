void main()
{
    int up = 40, down = -30, hold = 4;      // Motor speed going up and down
    int first, second, third;               // Buttons at each floor
    int one = 30, two = 120, three = 200;   // Adjust for tolerance of each floor, mm from sonar
    int t = 1;                              // Floor count
    
    tone(659.26,0.15);                      // Mario Music
    tone(659.26,0.3);
    tone(659.26,0.15);
    sleep(0.15);
    tone(523.25,0.15);
    tone(659.26,0.3);
    tone(783.99,0.6);
    tone(392.00,0.6);
    
    while(1)                                // While loop keeps the code repeating
      {
        printf("\nFloor 1,2,or 3?");
        first=digital(9);
        second=digital(11);                 // Reads buttons at all floors
        third=digital(13);
        if(first==0)
        {
            if(second==0)
            {
                if(third==0){}              // If loops depending on the button being pressed
                //  If the 3rd floor button is pressed, the code will read the sonar to see where the elevator is
                else
                {
                    beep();
                    if(t==3)
                    {    
                        printf("\nThe elevator is already on Floor 3!");
                        sleep(1.0);
                    }
                    else
                    {
                        if(t==3)
                        {        
                            printf("\nThe elevator is already on Floor 3!");
                            sleep(1.0);
                        }
                        else                // Brings the Elevator up to the 3rd floor
                        {         
                            printf("\nComing up to Floor 3");
                            t=3;
                            while(sonar()<three)
                            {
                                motor(1,up);
                            }
                            beep();
                            motor(1,hold);
                        }
                    }
                }
            }
            // If the 2nd floor button is pressed, the code will read the sonar to see where the elevator is
            else
            {
                beep();
                if(t==2)
                {
                    printf("\nThe elevator is already on Floor 2!");
                    sleep(1.0);
                }
                else                    // Brings the Elevator up to the 2nd Floor
                {                   
                    if(sonar()<two)
                    {
                        printf("\nComing up to Floor 2");
                        t=2;
                        while(sonar()<two)
                        {
                            motor(1,up);
                        }
                        beep();
                        motor(1,hold);
                    }
                    else                // Brings Elevator down to 2nd floor
                    {                
                        printf("\nComing down to Floor 2");
                        t=2;
                        while(sonar()>two)
                        {
                            motor(1,down);
                        }
                        beep();
                        motor(1,hold);
                    }
                }
            }
        }
        // If the 1st floor button is pressed, the code will read the sonar to see where the elevator is
        else
        {
            beep();
            if(t==1)
            {
                printf("\nThe elevator is already on Floor 1!");
                sleep(1.0);
            }
            else
            {                    
                if(t==1)
                {
                    printf("\nThe elevator is already on Floor 1!");
                    sleep(1.0);
                }
                else                    // Bring Elevator down to 1st floor
                {                                      
                    printf("\nComing down to Floor 1");
                    t=1;
                    while(sonar()>one)
                    {
                        motor(1,down);
                    }
                    beep();
                    ao();
                }
            }
        }
    }
}