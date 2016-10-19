 
#define INCL_BASE
#define INCL_DOS
#define INCL_SUB
#define INCL_DOSMISC
#define INCL_DOSPROCESS
 
#include <os2.h>
#include <math.h>
 
int notetime = 50;
long resttime = 20l;
double start = 100.0,stop = 3200.0,freq;
 
main()
{
        double hstep,tonic;
 
        printf("Audible Multitasking Indicator: ARPEGGIO \n");
        printf("Copyright (c) 1987, PC TECH JOURNAL ");
        printf("and Ziff Communications Co.\n");
        printf("  Written by Ted Mirecki \n\n");
 
                /* half-step frequency ratio = twelfth root of two) */
 
        hstep = pow(2.0,(double)(1.0/12.0));
        while(1)
        {
                for(tonic=start;tonic <= stop; tonic *= 2.0)
                {
                        freq = tonic;
                        note();
                        freq *= hstep* hstep * hstep * hstep;
                        note();
                        freq *= hstep * hstep * hstep;
                        note();
                }
                for(;tonic > start; tonic /= 2.0)
                {
                        freq = tonic;
                        note();
                        freq /= hstep * hstep * hstep;
                        note();
                        freq /= hstep * hstep * hstep * hstep;
                        note();
                }
        }
}
 
                /* Isolate OS calls in separate function */
 
note()
{
        int ihertz;
 
        ihertz = (int)(freq + 0.5);
        DosBeep(ihertz,notetime);
        DosSleep(resttime);
}
 
