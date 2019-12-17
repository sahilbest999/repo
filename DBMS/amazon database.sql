CREATE DATABASE Amazon_;
use Amazon_;

create table product(prod_id int NOT NULL primary key,prod_name varchar(20) NOT NULL,prod_price int NOT NULL);
create table customer(cust_id int NOT NULL primary key,cust_firstname varchar(20) NOT NULL,cust_lastname varchar(20) NOT NULL,cust_phone int NOT NULL,cust_email varchar(20),cust_address varchar(30));
create table seller(seller_id int  NOT NULL primary key,seller_name varchar(20) NOT NULL,seller_phone int NOT NULL,seller_email varchar(20) NOT NULL,seller_address varchar(30));
create table shipper( shipper_id int NOT NULL primary key,shipper_name varchar(20) NOT NULL,shipper_phone int NOT NULL,shipper_email varchar(20) NOT NULL);
create table order_(order_id int ,cust_id int NOT NULL primary key,prod_id int ,seller_id int ,shipper_id int ,status_id varchar(20));
create table status(status_id int primary key,status_name varchar(20));

create table amazon
(
prod_id int NOT NULL ,FOREIGN KEY (prod_id) REFERENCES product(prod_id),
cust_id int NOT NULL,FOREIGN KEY (cust_id) REFERENCES customer(cust_id),
seller_id int NOT NULL,FOREIGN KEY (seller_id) REFERENCES seller(seller_id),
shipper_id int NOT NULL,FOREIGN KEY (shipper_id) REFERENCES shipper(shipper_id),
order_id int ,
status_id int NOT NULL,FOREIGN KEY (status_id) REFERENCES status(status_id)
);
