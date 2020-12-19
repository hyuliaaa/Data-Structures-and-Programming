int main()
{
   int x=10;
   int &y=x;
   
   
   int a;
   a=x; //here x is used on right handside of assingment (so here x is r-value) whatever is in x has to         //be stored in a   , r-value is a data, literal, constant values
   x=25;  // here x is l-value, x is giving the location where this 25 should be written 
   return 0;
   
   //Reference does not consume any memory at all!!!
   //once a reference is initialized, you cannot change it!!!
   
 }
