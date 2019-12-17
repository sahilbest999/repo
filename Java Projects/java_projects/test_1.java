import java.util.*;


class test_1
{
    public static void procedure(int a[],int size)
    {
     int total = 0,i = 0;
     while(i!=size)
     {
        total += a[i]; 
        ++i;
     }
        System.out.println("Total = "+total);
    }
    
    public static void get_data()
    {
        int size = 0,a[] = new int[1000];
        String data="Null";
        Scanner input = new Scanner(System.in);
        while(data!="done")
        {
            data = input.next();
            if(data=="done"&&size==0)
            {
                System.out.println("Exit code -1");
                System.out.println("Atleast Enter 2 Intergers to Add");
                break;
            }
            else
            {
             System.out.println("Invoked");
             a[size] = Integer.parseInt(data);
             ++size;
            }
        }
        if(size == 0)
        get_data();
        
        procedure(a,size);
    }
    
    public static void main(String args[])
    {  
        get_data();
    }
}