CREATE DATABASE Amazon_;
use Amazon_;

create table product(prod_id int NOT NULL primary key,prod_name varchar(20) NOT NULL,prod_price int NOT NULL);
create table customer(cust_id int NOT NULL primary key,cust_firstname varchar(20) NOT NULL,cust_lastname varchar(20) NOT NULL,cust_phone int NOT NULL,cust_email varchar(20),cust_address varchar(30));
create table seller(seller_id int  NOT NULL primary key,seller_name varchar(20) NOT NULL,seller_phone int NOT NULL,seller_email varchar(20) NOT NULL,seller_address varchar(30));
create table shipper( shipper_id int NOT NULL primary key,shipper_name varchar(20) NOT NULL,shipper_phone int NOT NULL,shipper_email varchar(20) NOT NULL);
create table order_(order_id int ,cust_id int NOT NULL primary key,prod_id int ,seller_id int ,shipper_id int ,status_id varchar(20));
create table status(status_id int primary key,status_name varchar(20));

insert into product values(001,'HARD DISK',2000);
insert into product values(002,'RAM',3000);
insert into product values(003,'WEBCAM',500);
insert into product values(004,'GPU',13000);
insert into product values(005,'HEADPHONES',1500);
insert into product values(006,'MOUSE',2500);
insert into product values(007,'KEYBOARD',4000);
insert into product values(008,'MONITOR',8000);
insert into product values(009,'CPU CABINATE',6000);
insert into product values(010,'PSU',4500);

insert into customer values(101,'SAHIL','SHAHANE',989065809,'sahil@gmail.com','PUNE');
insert into customer values(102,'UTTKARSH','PATEL',808799660,'uttk@gmail.com','SWARGATE');
insert into customer values(103,'PRATHMESH','SATPUTE',883002993,'polo@gmail.com','HADAPSAR');
insert into customer values(104,'SHWET','PATHAK',820840838,'shwet@gmail.com','KOTHRUD');
insert into customer values(105,'MUIZZ','SHIEK',960444608,'muizz@gmail.com','BANER');
insert into customer values(106,'JAYASHRI','GHORPADE',966573256,'jayas@gmail.com','UNKNOWN');
insert into customer values(107,'SHRUTI','SHAHANE',932582776,'shruti@gmail.com','PUNE');
insert into customer values(108,'VANSHAJ','NATHANI',842121390,'vans@gmail.com','PUNE');
insert into customer values(109,'ANUSHKA','SHETTY',777600508,'anu@gmail.com','BAVDHAN');
insert into customer values(110,'PRATHMESH','LONKAR',907551875,'lonkar@gmail.com','CHINCHWAD');

insert into shipper values(301,'IAFCS',982305756,'IAFCS@gmail.com');
insert into shipper values(302,'DHL Express',902800282,'DHL@gmail.com');
insert into shipper values(303,'ORIGIN',203250085,'ORIGIN@gmail.com');
insert into shipper values(304,'FedEx',886072593,'FedEx@gmail.com');
insert into shipper values(305,'SPEEDEX',202748757,'SPEEDEX@gmail.com');

insert into seller values(201,'JAGDAMBA ELEC.',998691426,'jagd@gmail.com','PUNE');
insert into seller values(202,'AMBIKA ELEC.',887012660,'ambika@gmail.com','KOTHRUD');
insert into seller values(203,'CHROMA',206889019,'chroma@gmail.com','ASSAM');
insert into seller values(204,'RADHIKA ELEC.',779015689,'radhika@gmail.com','BANGLORE');
insert into seller values(205,'VIJAY SALES',915672554,'vijaysales@gmail.com','DELHI');


insert into status values(1,'PROCESSING');
insert into status values(2,'PROCESSED');
insert into status values(3,'FAILED');

insert into order_ values(NULL,101,NULL,NULL,NULL,3);
insert into order_ values(501,102,02,203,304,2);
insert into order_ values(502,106,05,204,303,2);
insert into order_ values(503,108,06,202,302,2);
insert into order_ values(504,110,08,203,305,2);
insert into order_ values(505,105,01,205,304,2);
insert into order_ values(506,104,07,203,302,2);
insert into order_ values(NULL,103,NULL,NULL,NULL,3);
insert into order_ values(507,109,04,202,301,2);
insert into order_ values(NULL,107,NULL,NULL,NULL,3);


select 
cust_firstname as 'First Name',
cust_lastname as 'Last Name',
cust_phone as 'Customer Phone',
cust_email as 'Customer Email',
cust_address as 'Customer Address',
prod_name as 'Product',
prod_price as 'Product Price',
seller_name as 'Seller',
seller_phone as 'Seller Phone',
seller_email as 'Seller Email',
seller_address as 'Seller Address',
shipper_name as 'Shipper',
shipper_phone as 'Shipper Phone',
shipper_email as 'Shipper Email',
status_name as 'Status'
from order_ o

JOIN customer c
	ON o.cust_id = c.cust_id

JOIN product p
	ON o.prod_id = p.prod_id

JOIN seller se
	ON o.seller_id = se.seller_id

JOIN shipper s
	ON o.shipper_id = s.shipper_id

JOIN status st
	ON o.status_id = st.status_id
    
ORDER BY o.order_id;


