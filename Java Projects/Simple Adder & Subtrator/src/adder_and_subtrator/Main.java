package adder_and_subtrator;

import java.util.*;

public class Main{
	
	static String data[]=new String[100000];
	static int i=0,size=0,total=0,ch=0;
	public static void get_data()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Your Data [Type 'exit' when finished entering data]:");
		for(i=0;true;i++)
		{
			data[i] = sc.next();
			if(data[i].contentEquals("exit"))
				break;
			++size;
		}
	}
	
	public static void procedure()
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("1.Addition");
		System.out.println("2.Substraction");
		System.out.println("3.Multiplication");
		ch=sc.nextInt();
		
		switch(ch)
		{
		case 1:
			get_data();
			for(i=0;i<size;i++)
			{
				total += Integer.parseInt(data[i]);
			}
			break;
		case 2:
			get_data();
			for(i=0;i<size;i++)
			{
				total -= Integer.parseInt(data[i]);
			}
			break;
		case 3:
			get_data();
			for(i=0;i<size;i++)
			{
				total *= Integer.parseInt(data[i]);
			}
			break;
		default:
				System.out.println("Wrong Choice");
			break;
		}
		if(ch>=1&&ch<=3)
		System.out.println("Total = "+total);
	}
	
	public static void main(String args[])
	{
		procedure();
	}
}