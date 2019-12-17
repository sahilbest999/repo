use amazon_;

select * from order_ o

JOIN customer c
	ON o.cust_id = c.cust_id

JOIN product p
	ON o.prod_id = p.prod_id

JOIN seller se
	ON o.seller_id = se.seller_id

JOIN shipper s
	ON o.shipper_id = s.shipper_id

JOIN status st
	ON o.status_id = st.status_id;
