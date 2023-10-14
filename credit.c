#include <stdio.h>

int get_digits(unsigned long int card_num);
int check(unsigned long int card_num);
unsigned int get_digits2(unsigned int num);

int main(void) {
  unsigned long int card_num;
  int count = 0;
  int sum = 0;
  int digit;
  
  printf("Enter card number: ");
  scanf("%lu", &card_num);

  count = check(card_num);

  if(count != 13 && count != 15 && count != 16)
  {
    printf("Invalid\n");
    return 0;
  }

  sum = get_digits(card_num);

  digit = sum % 10;
  
  //Checks if last digit of algorithm is 0
  if(digit != 0)
  {
    printf("Invalid\n");
    return 0;
  }
  
  //Checks if first digits are valid card numbers 
  if((count == 15) && ((card_num / 10000000000000) == 37 || (card_num / 10000000000000) == 34))
  {
    printf("Amex\n");
  }
  else if(((count == 13) && (card_num / 10000000000000) == 4) || ((count == 16) && ((card_num /         1000000000000000) == 4)))
  {
    printf("Visa\n");
    
  }
  else if((count == 16) && ((card_num / 100000000000000) >= 51) || ((count == 16) && (card_num / 100000000000000) <= 55))
  {
    printf("Mastercard\n");
  }
  else
  {
    printf("Invalid\n");
    return 0;
  }
  return 0;
}

//Gets individual digits of second to last mult by 2 
unsigned int get_digits2(unsigned int num){
  unsigned int digit;
  unsigned int sum = 0;

  digit = (num % 10) * 2;
  num = num / 10;
  sum += digit;
  return sum;
}

int get_digits(unsigned long int card_num){
  unsigned int last_digit, second_digit;
  unsigned int last_sum = 0, second_last_sum = 0, total_sum = 0;
  unsigned int digit = 0, digit_sum = 0;
  
  do
  {
    //Gets every last digit and adds them
    last_digit = card_num % 10;
    last_sum += last_digit;
    card_num = card_num / 10;

    //Gets second to last digit 
    second_digit = card_num % 10;
    card_num = card_num / 10;

    //Passes to function and returns digits of second to last digits
    second_last_sum = get_digits2(second_digit);

    //Gets digits of second last digits and adds them 
    while(second_last_sum != 0)
      {
        digit = second_last_sum % 10;
        second_last_sum = second_last_sum / 10;
        digit_sum += digit;
      }

  } while(card_num != 0);

  total_sum = last_sum + digit_sum;
  
  return total_sum;
}

//Gets number of digits within card number
int check(unsigned long int card_num){
  int count = 0;
  
  while(card_num != 0)
  {
    card_num = card_num / 10;
    count++;
  }
  
return count;
}
