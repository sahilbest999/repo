package adder_and_subtrator;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main implements ActionListener
{
	JFrame main_frame;
	Container c;
	JButton add_b,sub_b,div_b,mul_b;
	Font font_abs_bold,font_abs;
	Color matt_black = new Color(23,23,23);
	TextField t1,t2,t3;
	JLabel operator,equal,ans;
	Number sum;
	public void Main_frame()
	{
		main_frame = new JFrame("Simple Calculator");
		main_frame.setBounds(100,100,600,150);
		main_frame.setLayout(null);
		main_frame.setVisible(true);
		main_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		main_frame.setResizable(false);
		c = main_frame.getContentPane();
		
		fonts();
		buttons();
		textfields();
		labels();
		
		c.setBackground(matt_black);
		c.revalidate();
	}
	public void buttons()
	{
		add_b = new JButton("ADD");
		add_b.setBounds(30,80,100,30);
		add_b.setBackground(matt_black);
		add_b.setForeground(Color.WHITE);
		add_b.setFont(font_abs);
		add_b.addActionListener(this);
		
		sub_b = new JButton("SUBTRACT");
		sub_b.setBounds(140,80,100,30);
		sub_b.setBackground(matt_black);
		sub_b.setForeground(Color.WHITE);
		sub_b.setFont(font_abs);
		sub_b.addActionListener(this);
		
		div_b = new JButton("DIVIDE");
		div_b.setBounds(250,80,100,30);
		div_b.setBackground(matt_black);
		div_b.setForeground(Color.WHITE);
		div_b.setFont(font_abs);
		div_b.addActionListener(this);
		
		mul_b = new JButton("MULTIPLY");
		mul_b.setBounds(360,80,100,30);
		mul_b.setBackground(matt_black);
		mul_b.setForeground(Color.WHITE);
		mul_b.setFont(font_abs);
		mul_b.addActionListener(this);
		
		c.add(add_b);
		c.add(sub_b);
		c.add(div_b);
		c.add(mul_b);
	}
	public void fonts()
	{
		font_abs = new Font("Trebuchet MS",Font.PLAIN,12);
		font_abs_bold = new Font("Trebuchet MS",Font.BOLD,17);
	}
	public void textfields()
	{
		t1 = new TextField();
		t1.setBounds(30+10,30,80,30);
		t1.setFont(font_abs_bold);
		
		t2 = new TextField();
		t2.setBounds(140+10,30,80,30);
		t2.setFont(font_abs_bold);
		
		c.add(t1);
		c.add(t2);
	}
	public void labels()
	{
		operator = new JLabel();
		operator.setBounds(118+10,10,70,70);
		operator.setForeground(Color.GREEN);
		operator.setFont(new Font("Trebuchet MS",Font.BOLD,25));
		
		equal = new JLabel("=");
		equal.setBounds(228+10,10,70,70);
		equal.setForeground(Color.GREEN);
		equal.setFont(new Font("Trebuchet MS",Font.BOLD,25));
		
		ans = new JLabel();
		ans.setBounds(265,10,400,72);
		ans.setForeground(Color.GREEN);
		ans.setFont(new Font("Trebuchet MS",Font.BOLD,25));
		
		c.add(operator);
		c.add(equal);
		c.add(ans);
		
	}
	public void Calculation(String s1,String s2,int ch)
	{
		switch(ch)
		{
		case 1:
		try
		{
			ans.setText(Long.toString(Long.parseLong(s1) + Long.parseLong(s2)));
			operator.setText("+");
		}
		catch(Exception e)
		{
			
		}
		break;
		case 2:
			try
			{
				ans.setText(Long.toString(Long.parseLong(s1) - Long.parseLong(s2)));
				operator.setText("-");
			}
			catch(Exception e)
			{
				
			}
			break;
		case 3:
			try
			{
				ans.setText(Long.toString(Long.parseLong(s1) / Long.parseLong(s2)));
				operator.setText("÷");
			}
			catch(Exception e)
			{
				
			}
			break;
		case 4:
			try
			{
				ans.setText(Long.toString(Long.parseLong(s1) * Long.parseLong(s2)));
				operator.setText("x");
			}
			catch(Exception e)
			{
				
			}
			break;
		}
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if((t1.getText())!=null&&(t2.getText())!=null)
			{
				if(e.getSource()==add_b)
				{
					Calculation(t1.getText(),t2.getText(),1);
				}
				else if(e.getSource()==sub_b)
				{
					Calculation(t1.getText(),t2.getText(),2);
				}
				else if(e.getSource()==div_b)
				{
					Calculation(t1.getText(),t2.getText(),3);
				}
				else if(e.getSource()==mul_b)
				{
					Calculation(t1.getText(),t2.getText(),4);
				}
			}
	}

	public static void main(String args[])
	{
		Main obj = new Main();
		obj.Main_frame();
	}
}
