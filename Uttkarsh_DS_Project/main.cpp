
int main()
{
	int choice,ch,disp;
	char name[20],last[20],email[40],display[100];  // the display array is for the read cart 
	long int credit,total;
	
	printf("1. SHOP\n");
	printf("2. Go TO CART\n");
	
	printf("\n\nEnter : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:	
		printf("Menu :- \n");
		printf("1. OnePlus 7 Pro --------------------------- 48000Rs\n");
		printf("2. iPhone 11 ------------------------------- 64000Rs\n");
		printf("3. Xaiomi Mi A3 ---------------------------- 12000Rs\n");
		printf("4. Nokia 3310 ------------------------------ 3179Rs\n");
		printf("5. Redmi K20Pro ---------------------------- 23000Rs\n");
		printf("6. Asus ROG phone 2 ------------------------ 38000Rs\n");
		printf("7. Google Pixel 3 -------------------------- 43000Rs\n");
		printf("8. Samsung S10 Plus ------------------------ 74000Rs\n");
		printf("9. Samsung Note 10 ------------------------- 70000Rs\n");
		printf("10. Redmi Note 7 Pro ----------------------- 15000Rs\n");
		
		printf("\nEnter the number: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				total = 48000;
			break;
			case 2:
				total = 64000;
			break;	
			case 3: 
				total = 12000;
			break;
			case 4:
				total = 3179;
			break;
			case 5:
				total = 23000;
			break;
			case 6:
				total = 38000;
			break;
			case 7:
				total = 43000;
			break;
			case 8:
				total = 74000;
			break;
			case 9:
				total = 70000;
			break;
			case 10:
				total = 15000;
			break;
			default:
				printf("Enter a valid number");
		}
	
		FILE *fptr;
		fptr = fopen("DATA.txt","w");
		
		printf("Enter your name: ");
		scanf("%s",name);
		fprintf(fptr,"%s",name);
		
		printf("Enter your last name: ");
		scanf("%s",last);
		fprintf(fptr,"%s",last);
		
		printf("Enter Email ID: ");
		scanf("%s",email);
		fprintf(fptr,"%s",email);
		
		printf("Enter Creditcard No - ");
		scanf("%ld",&credit);
		fprintf(fptr,"%ld",credit);
		
		FILE *cart;
		cart = fopen("CART.txt","w");		//the cart values are stored seperately in a different file
		putw(total,cart);
		
		printf("ORDER PLACED SUCCESSFULLY");
		fclose(fptr);
		break;
		
		case 2:
			FILE *rptr=NULL;
		
			rptr = fopen("CART.txt","r");
			
			if(rptr == NULL)
			{
				printf("Cart is empty");
				exit(1);
			}
			
			while(total = getw(rptr) != EOF)
			{
				printf("%d",total);
			}

			break;
		default:
			printf("Enter a valid choice");
	}
	
	return 0;
}

//			rptr = fopen("DATA.txt","w+");

