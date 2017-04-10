
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    digitalWrite(redPin, HIGH);  
    //use led to visualize the notes being played
    
    int x;   
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)   
    {    
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    }    
    
    digitalWrite(redPin, LOW);
    //set led back to low
    
    delay(20);
    //a little delay to make all notes sound separate
}    
     
void march()
{    
    //for the sheet music see:
    //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    //this is just a translation of said sheet music to frequencies / time in ms
    //used 500 ms for a quart note
    
    beep(speakerPin, a, 500); 
    beep(speakerPin, a, 500);     
    beep(speakerPin, a, 500); 
    beep(speakerPin, f, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //first bit
    
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);    
    beep(speakerPin, fH, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, gS, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //second bit...
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //start of the interesting bit
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 125);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, a, 125); 
    
    beep(speakerPin, cH, 500); 
    beep(speakerPin, a, 375);  
    beep(speakerPin, cH, 125); 
    beep(speakerPin, eH, 1000); 
    //more interesting stuff (this doesn't quite get it right somehow)
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //repeat... repeat
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 250);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, cH, 125); 
           
    beep(speakerPin, a, 500);            
    beep(speakerPin, f, 375);            
    beep(speakerPin, c, 125);            
    beep(speakerPin, a, 1000);    
    soft_restart();   
    //and we're done \ó/    
}
