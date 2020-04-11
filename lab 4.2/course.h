class Course {
private:
    int code, credits;
    char letterGrade;
public:
    Course(int code, int credits, char letterGrade): code(code), credits(credits), letterGrade(letterGrade) {}

    int getCode() const {return code;}
    int getCredits() const {return credits;}
    char getLetterGrade() const {return letterGrade;}
    
    double getNumericGrade() const {
        if (letterGrade == 'A') 
            return 4.0;
        else if (letterGrade == 'B')
            return 3.0;
        else if (letterGrade == 'C')
            return 2.0;
        else if (letterGrade == 'D')
            return 1.0;
        else
            return 0.0;
    }
};