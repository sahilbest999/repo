package asd;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Main2 implements ActionListener,ItemListener,KeyListener,MouseListener,MouseMotionListener,WindowListener,FocusListener
{
	String []state_arr = {
			"Andhra Pradesh",
			"Arunachal Pradesh",
			"Assam",
			"Bihar",
			"Goa",
			"Gujarat",
			"Haryana",
			"Himachal Pradesh",
			"Jammu & Kashmir",
			"Karnataka",
			"Kerala",
			"Madhya Pradesh",
			"Maharashtra",
			"Manipur",
			"Meghalaya",
			"Mizoram",
			"Nagaland",
			"Orissa",
			"Punjab",
			"Rajasthan",
			"Sikkim",
			"Tamil Nadu",
			"Tripura",
			"Uttar Pradesh",
			"West Bengal",
			"Chhattisgarh",
			"Uttarakhand",
			"Jharkhand",
			"Telangana",
			};
	
	JFrame main_frame;
	Container c;
	JButton add_b,sub_b,div_b,mul_b,submit_b,clear_ta,dragme;
	Font font_abs_bold,font_abs,font_reg;
	Color matt_black = new Color(23,23,23),matt_blue = new Color(00,255,255);
	JTextField t1,t2,t3,t_name;
	JTextArea t_a1;
	JLabel operator,equal,ans,name,gender,state,Item_example,Item_example2,l_menu_logo,window_focus;
	Number sum;
	Cursor cur_hand;
	Image title_icon;
	JRadioButton rb_gen_male,rb_gen_female;
	JComboBox state_cb;
	ButtonGroup genders = new ButtonGroup();
	JCheckBox tnc;
	ImageIcon menu_logo;
	int dragme_dragging = 0;
	
	Main2()
	{
		main_frame = new JFrame("JavaGUI Example");
		//main_frame.setBounds(40,0,1280,720);
		main_frame.setBounds(40,0,600,500);
		main_frame.setLayout(null);
		main_frame.setVisible(true);
		main_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		main_frame.setResizable(false);
		title_icon = Toolkit.getDefaultToolkit().getImage("C:\\Users\\poly.lab\\Downloads\\repo-master\\repo-master\\JavaGUI Example\\calculatorMedium.png");
		menu_logo = new ImageIcon("C:\\Users\\poly.lab\\Downloads\\repo-master\\repo-master\\JavaGUI Example\\circle_small.png");
		main_frame.setIconImage(title_icon); //FOR PROGRAM's ICON
		main_frame.addKeyListener(this);
		main_frame.addWindowListener(this);
		//main_frame.setContentPane(new JLabel(new ImageIcon("C:\\Users\\Administrator\\Desktop\\img2.jpg"))); //USE THIS TO SET BACKGROUND IMAGE
		c = main_frame.getContentPane();
		
		
		cursors();
		fonts();
		buttons();
		textfields();
		labels();
		
		c.setBackground(matt_black);
		c.revalidate();
		System.gc();
	}
	public void buttons()
	{
		add_b = new JButton("ADD");
		add_b.setBounds(30,80,100,30);
		add_b.setBackground(matt_black);
		add_b.setForeground(Color.WHITE);
		add_b.setFont(font_abs);
		add_b.addActionListener(this);
		add_b.setCursor(cur_hand);
		
		sub_b = new JButton("SUBTRACT");
		sub_b.setBounds(140,80,100,30);
		sub_b.setBackground(matt_black);
		sub_b.setForeground(Color.WHITE);
		sub_b.setFont(font_abs);
		sub_b.addActionListener(this);
		sub_b.setCursor(cur_hand);
		
		div_b = new JButton("DIVIDE");
		div_b.setBounds(250,80,100,30);
		div_b.setBackground(matt_black);
		div_b.setForeground(Color.WHITE);
		div_b.setFont(font_abs);
		div_b.addActionListener(this);
		div_b.setCursor(cur_hand);
		
		mul_b = new JButton("MULTIPLY");
		mul_b.setBounds(360,80,100,30);
		mul_b.setBackground(matt_black);
		mul_b.setForeground(Color.WHITE);
		mul_b.setFont(font_abs);
		mul_b.addActionListener(this);
		mul_b.setCursor(cur_hand);
		
		rb_gen_male = new JRadioButton("Male");
		rb_gen_male.setBounds(91,160+24,53,25);
		rb_gen_male.setFont(new Font("Trebuchet MS",Font.BOLD,13));
		rb_gen_male.setForeground(Color.WHITE);
		rb_gen_male.setBackground(matt_black);
		rb_gen_male.setSelected(true);
		rb_gen_male.setCursor(cur_hand);
		
		rb_gen_female = new JRadioButton("Female");
		rb_gen_female.setBounds(91+55,160+24,70,25);
		rb_gen_female.setFont(new Font("Trebuchet MS",Font.BOLD,13));
		rb_gen_female.setForeground(Color.WHITE);
		rb_gen_female.setBackground(matt_black);
		rb_gen_female.setCursor(cur_hand);
		
		genders.add(rb_gen_male);
		genders.add(rb_gen_female);
		
		state_cb = new JComboBox(state_arr);
		state_cb.setBounds(91,160+63,130,25);
		state_cb.addActionListener(this);
		state_cb.addItemListener(this);
		
		submit_b = new JButton("SUBMIT");
		submit_b.setBounds(91,160+145,100,25);
		submit_b.setForeground(Color.RED);
		submit_b.setBackground(matt_black);
		submit_b.setFont(font_abs_bold);
		submit_b.addActionListener(this);
		
		tnc = new JCheckBox("I Have Accepted Your Terms and Conditions");
		tnc.setBounds(25,160+105,300,25);
		tnc.setBackground(matt_black);
		tnc.setForeground(Color.WHITE);
		tnc.addActionListener(this);
		tnc.addItemListener(this);
		
		clear_ta = new JButton("Clear Text Area");
		clear_ta.setBounds(330,325,200,20);
		clear_ta.setForeground(Color.WHITE);
		clear_ta.setBackground(matt_black);
		clear_ta.setFont(font_abs);
		clear_ta.addActionListener(this);
		clear_ta.addMouseListener(this);
		
		dragme = new JButton("Drag Me!");
		dragme.setBackground(matt_black);
		dragme.setForeground(Color.WHITE);
		dragme.setFont(font_abs);
		dragme.setCursor(cur_hand);
		dragme.setBounds(300-70,415,100,30);
		dragme.addMouseListener(this);
		dragme.addMouseMotionListener(this);
		
		c.add(add_b);
		c.add(sub_b);
		c.add(div_b);
		c.add(mul_b);
		c.add(rb_gen_male);
		c.add(rb_gen_female);
		c.add(state_cb);
		c.add(tnc);
		c.add(submit_b);
		c.add(clear_ta);
		c.add(dragme);
	}
	public void fonts()
	{
		font_abs = new Font("Trebuchet MS",Font.PLAIN,12);
		font_abs_bold = new Font("Trebuchet MS",Font.BOLD,17);
		font_reg = new Font("Trebuchet MS",Font.PLAIN,15);
	}
	public void textfields()
	{
		t1 = new JTextField();
		t1.setBounds(30+10,30,80,30);
		t1.setFont(font_abs_bold);
		
		t2 = new JTextField();
		t2.setBounds(140+10,30,80,30);
		t2.setFont(font_abs_bold);
		
		t_name = new JTextField();
		t_name.setBounds(91,143,95,25);
		t_name.setFont(font_abs_bold);
		t_name.addActionListener(this);
		t_name.addKeyListener(this);
		
		t_a1 = new JTextArea();
		t_a1.setBounds(330,143,200,182);
		t_a1.setFont(font_abs_bold);
		t_a1.setEditable(false);
		t_a1.addMouseListener(this);
		
		c.add(t_name);
		c.add(t1);
		c.add(t2);
		c.add(t_a1);
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
		
		name = new JLabel("Name");
		name.setBounds(30,140,50,30);
		name.setForeground(matt_blue);
		name.setFont(font_reg);
		
		gender = new JLabel("Gender");
		gender.setBounds(30,140+40,60,30);
		gender.setForeground(matt_blue);
		gender.setFont(font_reg);
		
		state = new JLabel("State");
		state.setBounds(30,140+80,50,30);
		state.setForeground(matt_blue);
		state.setFont(font_reg);
		
		Item_example = new JLabel("Example of a Item Listner.Try Changing the Terms and Condition CheckBox");
		Item_example.setBounds(30,350,580-12,30);
		Item_example.setForeground(matt_blue);
		Item_example.setFont(font_reg);
		
		Item_example2 = new JLabel("Example of a Item Listner.Try Changing the State Selection ComboBox");
		Item_example2.setBounds(30,380,580-12,30);
		Item_example2.setForeground(matt_blue);
		Item_example2.setFont(font_reg);
				
		l_menu_logo = new JLabel(menu_logo);
		l_menu_logo.setBounds(470,10,menu_logo.getIconWidth(),menu_logo.getIconHeight());
		
		window_focus = new JLabel("Focussing on this Window/Frame");
		window_focus.setBounds(30,413,200-10,30);
		window_focus.setForeground(Color.GREEN);
		window_focus.setFont(new Font("Trebuchet MS",Font.PLAIN,12));
		
		c.add(operator);
		c.add(equal);
		c.add(ans);
		c.add(name);
		c.add(gender);
		c.add(state);
		c.add(Item_example);
		c.add(Item_example2);
		c.add(l_menu_logo);
		c.add(window_focus);
	}
	public void cursors()
	{
		cur_hand = new Cursor(Cursor.HAND_CURSOR);
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
				ans.setText(Double.toString((double)Long.parseLong(s1) / (double)Long.parseLong(s2)));
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
	
	public void itemStateChanged(ItemEvent t)
	{
		if(t.getSource()==tnc)
		{
			if(t.getStateChange()==1)
			{
			Item_example.setForeground(Color.RED);
			}
			else
			{
			Item_example.setForeground(matt_blue);
			}
		}
		
		if(t.getSource()==state_cb)
		{
			if(t.getStateChange()==1)
			{
				if(state_cb.getSelectedIndex()==0)
					Item_example2.setForeground(Color.PINK);
				else if(state_cb.getSelectedIndex()==1)
					Item_example2.setForeground(Color.GREEN);
				else if(state_cb.getSelectedIndex()==2)
					Item_example2.setForeground(Color.YELLOW);
				else if(state_cb.getSelectedIndex()==3)
					Item_example2.setForeground(Color.BLUE);
				else if(state_cb.getSelectedIndex()==4)
					Item_example2.setForeground(Color.RED);
				else if(state_cb.getSelectedIndex()==5)
					Item_example2.setForeground(Color.ORANGE);
				else if(state_cb.getSelectedIndex()==6)
					Item_example2.setForeground(Color.PINK);
				else if(state_cb.getSelectedIndex()==7)
					Item_example2.setForeground(Color.GREEN);
				else if(state_cb.getSelectedIndex()==8)
					Item_example2.setForeground(Color.YELLOW);
				else if(state_cb.getSelectedIndex()==9)
					Item_example2.setForeground(Color.BLUE);
				else if(state_cb.getSelectedIndex()==10)
					Item_example2.setForeground(Color.RED);
				else if(state_cb.getSelectedIndex()==11)
					Item_example2.setForeground(Color.ORANGE);
				else if(state_cb.getSelectedIndex()==12)
					Item_example2.setForeground(Color.PINK);
				else if(state_cb.getSelectedIndex()==13)
					Item_example2.setForeground(Color.GREEN);
				else if(state_cb.getSelectedIndex()==14)
					Item_example2.setForeground(Color.YELLOW);
				else if(state_cb.getSelectedIndex()==15)
					Item_example2.setForeground(Color.BLUE);
				else if(state_cb.getSelectedIndex()==16)
					Item_example2.setForeground(Color.RED);
				else if(state_cb.getSelectedIndex()==17)
					Item_example2.setForeground(Color.ORANGE);
				else if(state_cb.getSelectedIndex()==18)
					Item_example2.setForeground(Color.PINK);
				else if(state_cb.getSelectedIndex()==19)
					Item_example2.setForeground(Color.GREEN);
				else if(state_cb.getSelectedIndex()==20)
					Item_example2.setForeground(Color.YELLOW);
				else if(state_cb.getSelectedIndex()==21)
					Item_example2.setForeground(Color.BLUE);
				else if(state_cb.getSelectedIndex()==22)
					Item_example2.setForeground(Color.RED);
				else if(state_cb.getSelectedIndex()==23)
					Item_example2.setForeground(Color.ORANGE);
				else if(state_cb.getSelectedIndex()==24)
					Item_example2.setForeground(Color.PINK);
				else if(state_cb.getSelectedIndex()==25)
					Item_example2.setForeground(Color.GREEN);
				else if(state_cb.getSelectedIndex()==26)
					Item_example2.setForeground(Color.YELLOW);
				else if(state_cb.getSelectedIndex()==27)
					Item_example2.setForeground(Color.BLUE);
				else if(state_cb.getSelectedIndex()==28)
					Item_example2.setForeground(Color.RED);
			}
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
		
		if(e.getSource()==tnc)
		{
			if(tnc.isSelected()==true)
			{
				submit_b.setForeground(Color.GREEN);
			}
			if(tnc.isSelected()==false)
			{
				submit_b.setForeground(Color.RED);
			}
		}
		
		if(e.getSource()==clear_ta)
		{
			t_a1.setText(null);
		}
	}
	
	public void keyPressed(KeyEvent k)
	{
		if(k.getSource()==t_name||k.getSource()==main_frame)
		{
			t_a1.append("Key Pressed - "+k.getKeyChar()+"\n");
		}
	}
	public void keyTyped(KeyEvent k)
	{
		
	}
	public void keyReleased(KeyEvent k)
	{
		
	}
	
	public void mouseEntered(MouseEvent m)
	{
		if(m.getSource()==clear_ta)
		{
				clear_ta.setForeground(Color.GREEN);
		}
		
		if(dragme_dragging==0)
		if(m.getSource()==dragme)
		{
			dragme.setForeground(Color.GREEN);
			dragme.setText("Drag Me!");
		}
		
	}
	public void mousePressed(MouseEvent m)
	{
		if(m.getSource()==dragme)
		{
			dragme.setBackground(Color.WHITE);
			dragme.setForeground(Color.BLACK);
			dragme.setText("Dragging...");
		}
		
	}
	public void mouseReleased(MouseEvent m)
	{
		if(m.getSource()==dragme)
		{
			dragme.setBackground(matt_black);
			dragme.setForeground(Color.WHITE);
			dragme.setText("Drag Me!");
			dragme_dragging=0;
		}
	}
	public void mouseClicked(MouseEvent m)
	{
		if(m.getSource()==dragme)
		{
			dragme.setBackground(matt_black);
			dragme.setForeground(Color.WHITE);
			dragme.setText("Drag Me!");
		}
	}
	public void mouseExited(MouseEvent m)
	{
		if(m.getSource()==clear_ta)
		{
			clear_ta.setForeground(Color.WHITE);
		}
		
		if(dragme_dragging==0)
		if(m.getSource()==dragme)
		{
			dragme.setBackground(matt_black);
			dragme.setForeground(Color.WHITE);
			dragme.setText("Drag Me!");
		}
	}
	public void mouseMoved(MouseEvent m)
	{
		
	}
	public void mouseDragged(MouseEvent m)
	{
		if(m.getSource()==dragme)
		{
			dragme_dragging = 1;
			dragme.setLocation(m.getX(),m.getY());
		}
	}
	
	public void windowActivated(WindowEvent w)
	{
		if(w.getSource()==main_frame)
		{
			window_focus.setText("Focussing on this Window/Frame");
			window_focus.setForeground(Color.GREEN);
		}
	}
	public void windowDeactivated(WindowEvent w)
	{
		if(w.getSource()==main_frame)
		{
			window_focus.setText("Not Focussing on this Window/Frame");
			window_focus.setForeground(Color.RED);
		}
	}
	public void windowIconified(WindowEvent w)
	{
		
	}
	public void windowDeiconified(WindowEvent w)
	{
		
	}
	public void windowOpened(WindowEvent w)
	{
		
	}
	public void windowClosing(WindowEvent w)
	{
		
	}
	public void windowClosed(WindowEvent w)
	{
		
	}
	
	public void focusGained(FocusEvent f)
	{
		
	}
	public void focusLost(FocusEvent f)
	{
		
	}

}


public class Main
{
	public static void main(String args[])
	{
		new Main2();
	}
}
