//
// Created by igor on 11.12.22.
//

#ifndef PARSER_RATIONAL_H
#define PARSER_RATIONAL_H


class Rational {
public:
    Rational(int numerator = 0, int denominator = 1) :
        numerator_(numerator),denominator_(denominator){
    }

    Rational& operator-=(const Rational &rational)  {
        numerator_ = numerator_ * rational.denominator_ - denominator_ * rational.numerator_;
        denominator_*= rational.denominator_;
        return *this;
    }
    Rational& operator+=(const Rational & rational) {
        numerator_ = numerator_ * rational.denominator_ + denominator_ * rational.numerator_;
        denominator_*= rational.denominator_;
        return *this;
    }


    Rational operator+() const {
        return {numerator_,denominator_};

    }
    Rational operator-() const {
        return {numerator_ * -1, denominator_};
    }

    Rational & operator*=(const Rational & rational){
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
        return *this;
    }
    Rational & operator/=(const Rational & rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
        return *this;
    }
    friend bool operator <(const Rational & lhs,const Rational & rhs);
    friend bool operator <=(const Rational & lhs,const Rational & rhs);
    friend bool operator >(const Rational & lhs,const Rational & rhs);
    friend bool operator >=(const Rational & lhs,const Rational & rhs);
    friend bool operator ==(const Rational & lhs,const Rational & rhs);
    friend bool operator !=(const Rational & lhs,const Rational & rhs);

    void neg() {
        numerator_ *= -1;
    };
    void inv(){
        if (numerator_ < 0 ) numerator_ *= -1;
    }
    double to_double() const {
        return static_cast<double>(numerator_) / denominator_;
    };
public:
    int get_numerator() const {
        return numerator_;
    }

    int get_denominator() const {
        return denominator_;
    }


private:
    int numerator_;
    int denominator_;
};

bool operator <(const Rational & lhs,const Rational & rhs){
    return (lhs.denominator_ * rhs.denominator_ > 0 && lhs.numerator_ * rhs.denominator_ < lhs.denominator_ * rhs.numerator_) ||
           (lhs.denominator_ * rhs.denominator_ < 0 && lhs.numerator_ * rhs.denominator_ > lhs.denominator_ * rhs.numerator_);
}
bool operator<=(const Rational &lhs, const Rational &rhs) {
    return !(lhs > rhs);
}

bool operator>(const Rational &lhs, const Rational &rhs) {
    return rhs < lhs;
}

bool operator>=(const Rational &lhs, const Rational &rhs) {
    return !(lhs < rhs);
}

bool operator==(const Rational &lhs, const Rational &rhs) {
    return !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
    return !(lhs == rhs);
}

Rational operator+(const Rational & lhs , const Rational & rhs){
    Rational r(lhs);
    r += rhs;
    return r;
}
Rational operator*(const Rational & lhs , const Rational & rhs){
    Rational r(lhs);
    r *= rhs;
    return r;
}
Rational operator/(const Rational & lhs , const Rational & rhs){
    Rational r(lhs);
    r /= rhs;
    return r;
}
Rational operator-(const Rational & lhs , const Rational & rhs){
    Rational r(lhs);
    r += rhs;
    return r;
}

#endif //PARSER_RATIONAL_H
