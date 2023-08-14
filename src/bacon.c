#include <bacon.h>
// Add other #includes here if you want.

int character_counter;
int cipherTextCharacters(char *text)
{
    character_counter=0;

    for(int i=0; i<(int)strlen(text);i++)
    {
        if(isalpha(text[i]))
        character_counter=character_counter+1;
    }
    return character_counter;
}

unsigned int returning;
unsigned int compute_Bits(char ch)
{
    returning=0;
    if(ch>=65 && ch<=90)
    {
     returning=ch -'A';
    }

    else if((ch>=44 && ch<=57)||ch==58||ch==59)
    {
        returning=ch-8;
    }

    else if(ch>=32 && ch<=41)
    {
        returning=ch-6;
    }
    
    else
    {
        returning=52;
    }
    
    return returning;
}

char returning_char;
char compute_plaintext(unsigned int var)
{
    returning_char='\0';

    if(var<=25)
    {
        returning_char=var+65;
    }
    else if(var>=26&&var<=35)
    {
        returning_char=var+6;
    }
    else if(var>=36&&var<=51)
    {
        returning_char=var+8; 
    }

    else if(var==52)
    returning_char=var+11;

    else if(var==63)
    returning_char=var+1;

    else
    returning_char='\0';

    return returning_char;
}


int total_characters;
int characters_required;
unsigned int current_bits;
int string_count;
int count;
unsigned int one_or_zero;

int encrypt(const char *plaintext, char *ciphertext) {
    characters_required=0;
    string_count=0;
    
   total_characters=cipherTextCharacters(ciphertext);

   if(total_characters<6)
   return -1;


  
   else{
   total_characters=total_characters-6;
   characters_required=total_characters/6;

   if(characters_required>((int)(strlen(plaintext))))
   characters_required=strlen(plaintext);

   count=0;

   for(int i=0;i<characters_required;i++)
   {
     count=0;
     current_bits=0;
     current_bits=compute_Bits(toupper(plaintext[i]));
     current_bits=current_bits<<26;

     while(count<6)
     {
      one_or_zero=0;
      one_or_zero=current_bits&0x80000000;
      one_or_zero=one_or_zero>>31;

      while(!isalpha(ciphertext[string_count]))
      string_count++;

      if(one_or_zero==0)
      {
        if(isupper(ciphertext[string_count]))
          ciphertext[string_count]=tolower(ciphertext[string_count]);
      }
      else
      {
       if(!isupper(ciphertext[string_count]))
       {
        ciphertext[string_count]=toupper(ciphertext[string_count]);
       }
      }

      string_count++;
      current_bits=current_bits<<1;
      count++;
     }
   }

   for(int i=0;i<6;i++)
   {
     while(!isalpha(ciphertext[string_count]))
     string_count++;

    ciphertext[string_count]=toupper(ciphertext[string_count]);
    string_count++;
   }

    return characters_required;
   }
}


int returning_value;
int bit_counter;
unsigned int bit_converter;
int value;
int plaintext_counter;
char check;
bool has_EOM;
bool is_Invalid;

int decrypt(const char *ciphertext, char *plaintext) {

    returning_value=0;
    plaintext_counter=0;
    has_EOM=false;
    is_Invalid=false;
    bit_counter=0x00000000;
    
    if((int)strlen(plaintext)==0){
    returning_value=-1;
    return returning_value;
    }

    else
    {
    int length=(int)strlen(plaintext);
    char copy_of_plaintext[length];

    for (int i = 0; i < length; i++) {
      copy_of_plaintext[i] = plaintext[i];
       }

      copy_of_plaintext[length] = '\0';

   
    for(int i=0; i<(int)strlen(ciphertext);i++)
    {
         if(!has_EOM)
     {
        value=0;
        
        if(isalpha(ciphertext[i]))
        {
          if(islower(ciphertext[i]))
          {
            value=0;
          }

          else
          {
             value=1;
          }

          bit_converter=bit_converter | value;
          bit_counter=bit_counter+1;

          if(bit_counter%6==0)
          {
             check=compute_plaintext(bit_converter);

             if(check==0){
             is_Invalid=true;
             }

             if(check==64){
             has_EOM=true;
             break;
             }

            if(!has_EOM && plaintext_counter<(int)strlen(plaintext)&& !is_Invalid){
            plaintext[plaintext_counter]=check;
            plaintext_counter=plaintext_counter+1;
            }

            bit_converter=bit_converter&0x00000000;
          }

          else
          {
            bit_converter=bit_converter<<1;
          }
        }
      }
    }

    if (!has_EOM)
    {
        returning_value=-2;
        plaintext=copy_of_plaintext;
        return returning_value;
    }

    if(is_Invalid)
    {
        returning_value=-3;
        plaintext=copy_of_plaintext;
        return returning_value;
    }

    if(has_EOM&&plaintext_counter<(int)strlen(plaintext))
    {
      plaintext[plaintext_counter]='\0';
      return plaintext_counter;
    }
        return plaintext_counter;
    }
}



    



