#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    // Check for invalid input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
     }
    
    char* input_file = argv[1];
    FILE* input_pointer = fopen(input_file, "r");
    if (input_file == NULL)
    {
        printf("Unable to open: %s\n", input_file);
        return 1;
    }
    unsigned char buffer[1024];
    
    char filename[8];
     int counter=0;
    FILE* output_pointer;
    int flag=0;
   while (fread(buffer, sizeof(buffer), 1, input_pointer))
   {
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
      {
        if(flag==1)
        {
        fclose(output_pointer);  //close file if already there 
        flag=0;
        }
        sprintf(filename, "%03i.jpg", counter);  // create new filename
        output_pointer = fopen(filename, "w");
        fwrite(buffer, sizeof(buffer), 1, output_pointer); // write current one to file
        flag=1;
        counter++;
      }
      
      else
      {
        if(flag==1) // doesn't start with jpeg header but buffer still carries it
        {
          fwrite(buffer, sizeof(buffer), 1, output_pointer);
        }
       }
    }
    
fclose(output_pointer);
fclose(output_pointer);

return 0;
}
      
   
        
    

               
