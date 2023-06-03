template < class First , class Second >
struct Pair {
Pair ( First const & first , Second const & second ) :
        first(first) ,
        second(second) {}
    First first ;
    Second second ;
};

template < class First , class Second >
Pair< First , Second > makePair ( First const & f , Second const & s ) {
    return Pair<First,Second >(f,s);
}
void foo ( Pair <int,double> const & p ) {

};
void bar () {
    foo ( Pair < int , double >(3 , 4.5));
    foo ( makePair (3 , 4.5));
}

int main(){
    bar();
}