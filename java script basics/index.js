let name='SAHIL lol'; //let is like declaring variable like int,long,string ,char
//var can also be used for declaring variables eg - var name = 'SAHIL';
let decimal=1.223;
const value = 'LOL';
//this is how we can declared a conntant value 
let is_approved = true;
let first_name = undefined, last_name = null;

console.log(value);
console.log(decimal);
console.log(name);
// the console.log(); commmand is u sed to display the elements 

typeof name;
//typeof is a operator which returns the datatype or type of data which is present in the variable
name = 1;
typeof name;
//now it will return name as "number"

let object = {

    name :'Sahil',
    age : 17
}; //CREATING A OBJECT AND ADDING DATA MEMBERS TO IT
//if you observer that the data members do not contain any semi colon they just contain ,[comma] for seperation of data members

console.log(object.name,object.age);
//this is used to access and display the information og the object

let array_name = ["SAHIL","SHWET","UTTKARSH","MUIZZ"];
let array_age = [17,17,20,17,16];
let array_something = ["SAHIL",17,'SHWET',18,"UTTKARSH",20];
// this is how to create array

let array_2D = [
    [1,2,3],
    [11,22,33]
];
//this is how to declare a 2D array

console.log(array_name.length);
//this is used to get array length

console.log(array_name[0]);
//this is used to get array element of 0th index/position

array_name[0] = "SHRUTI";
//this is how we change/modify the elements of a array 

console.log(array_name[0]);

let current_date = new Date();
//this is a current_date variable holds date,time,time zone of that particular computer

console.log(current_date);
//this is uesd to display the date,time,time zone of the particular computer

let particular_date = new Date(2018,9,13);// new Date(<year> ,<month> , <day> );
//this is used to store a particualr date in a identifier/variable

console.log(particular_date);

particular_date = new Date(2018,9,13,15,0,0,0);
// particular date with time new Date(<year> ,<month> ,<day> ,<hours> ,<minutes> ,<seconds> ,<milli-seconds>);

console.log(particular_date);

let a_string = "we took his bag, he said \"That\'s My Bag Mother fuckers\" .";
console.log(a_string);

//this is how we write apostophy in a string

let text1 = "My Name is " , text2 = "Sahil " , text3 = "and my Age is ", text4 = 17;
let text_combination  = text1+text2+text3+text4;
console.log(text_combination);

// OR

console.log("My Name is "+ "Sahil " +"and my Age is "+17);

let a = 5*'5';
console.log(a);
//it's nothing just a timepass thing

let i;
for(i=0;i<10;i++)
{
    console.log(i);
}
//this is for-loop in Java Script

i = 10;

while(i>=0)
{
    console.log(i);
    i--;
}
//this is while-loop in Java Script

//now you can predict do-while loop coz it's almost same like java & c++

let abc = 10,bed = 10;
console.log(abc==bed);
//just to check how comparison operator works

