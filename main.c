#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer
{
  int ac_num;
  int nid;
  char name[50];
  float balance;
  int s_pin;
  int s_counter;
};

int main(){

    struct customer* cval[50];


    //customer 1
    cval[0] = (struct customer*)malloc(sizeof(struct customer));
    cval[0]->ac_num      = 84648;
    cval[0]->nid         = 0;
    strcpy(cval[0]->name,"example");
    cval[0]->balance     = 56000;
    cval[0]->s_pin       = 9586;
    cval[0]->s_counter   = 2;


    //customer 2
    cval[1] = (struct customer*)malloc(sizeof(struct customer));
    cval[1]->ac_num      = 94698;
    cval[1]->nid         = 1;
    strcpy(cval[1]->name,"example1");
    cval[1]->balance     = 51000;
    cval[1]->s_pin       = 9686;
    cval[1]->s_counter   = 2;

    //customer 3
    cval[2] = (struct customer*)malloc(sizeof(struct customer));
    cval[2]->ac_num      = 64646;
    cval[2]->nid         = 2;
    strcpy(cval[2]->name,"example2");
    cval[2]->balance     = 59000;
    cval[2]->s_pin       = 9986;
    cval[2]->s_counter   = 2;

    //user define
    float dep,transfer;
    int ac,phn_num,dial,pin,counter,transaction=1,ni;

    printf("Dail: ");
    scanf("%d",&dial);

    if(dial == 989){
      printf("account number: ");
      scanf("%d",&ac);
      for(int i=0;i<3;i++){
        if(ac == cval[i]->ac_num){
          ni = cval[i]->nid;
        }
      }

        while(transaction == 1){

            int option;

            printf("\nMB-Degital\n");
            printf("1 - Send Money\n");
            printf("2 - Mobile Recharge\n");
            printf("3 - Payment\n");
            printf("4 - Account Info\n");

            printf("\nchoose option : ");
            scanf("%d",&option);

            switch(option){

                //Send Money
                case 1:
                printf("\nPhone No : ");
                scanf("%d",&phn_num);
                printf("\nAmmount: ");
                scanf("%f",&transfer);
                if(cval[ni]->balance>=transfer){
                        if(transfer<50000){
                        printf("\n4 digit pin: ");
                        scanf("%4d",&pin);
                        cval[ni]->balance-=transfer;
                        printf("\n%.2f successfully transfered\n\n",transfer);
                    }else{
                        printf("\nyou can't transfered more than 50000 in one time.\n\n");
                    }
                }
                else{
                    printf("\nyou do not have sufficient balance.your balance is %.2f\n\n",cval[ni]->balance);
                }
                break;



                //Mobile Recharge
                case 2:
                printf("\nPhone No : ");
                scanf("%d",&phn_num);
                printf("Ammount: ");
                scanf("%f",&dep);
                if(dep > 0 && dep<=2000){
                    printf("\n%.2f Successfully Recharge\n\n",dep);
                    cval[ni]->balance+=dep;
                }else{
                    printf("\nInvalid Recharge Amount\n");
                }
                break;



                //Payment
                case 3:
                printf("\nPhone No : ");
                scanf("%d",&phn_num);
                printf("Ammount TK : ");
                scanf("%f",&transfer);
                if(cval[ni]->balance>=transfer){
                    if(transfer<25000){
                        printf("\nCounter No : ");
                        scanf("%4d",&counter);
                        printf("\n4 digit pin : ");
                        scanf("%4d",&pin);
                        if(counter == cval[ni]->s_counter && pin == cval[ni]->s_pin){
                            cval[ni]->balance-=transfer;
                            printf("\n%.2f successfully Payment\n\n",transfer);
                        }else{
                            printf("\nwrong counter or pin\n");
                        }
                    }else{
                        printf("\nyou can't Payment more than 25000 in one time.\n\n");
                    }
                }else{
                    printf("\nyou do not have sufficient balance.your balance is %.2f\n\n",cval[ni]->balance);
                }
                break;


                //Account Info
                case 4:
                    printf("\nName: %s",cval[ni]->name);
                    printf("\nBalance: %.2f",cval[ni]->balance);
                    printf("\nAccount No: %d\n",cval[ni]->ac_num);
                break;



                //Default
                case 5:

                break;
                default:
                printf("invalid transaction\n");
            }

            transaction=0;

            printf("\nBack to main menu\n");
            printf("1. yes 2. no\n");
            scanf("%d",&transaction);
            if(transaction!=1 && transaction!=2){
                printf("invalid no.\nchoose between 1 and 2 only\n");
            }

        }


    }else{
        printf("Wrong Key");
    }

    return(0);
}
