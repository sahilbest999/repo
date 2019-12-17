use amazon_;

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

FULL JOIN customer c
	ON o.cust_id = c.cust_id

FULL JOIN product p
	ON o.prod_id = p.prod_id

FULL JOIN seller se
	ON o.seller_id = se.seller_id

FULL JOIN shipper s
	ON o.shipper_id = s.shipper_id

FULL JOIN status st
	ON o.status_id = st.status_id
    
ORDER BY o.order_id;
