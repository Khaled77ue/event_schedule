//
// Created by lamar on 1/1/2021.
//

#ifndef EX3_MTM_WINTER_EXCEPTIONS_H
#define EX3_MTM_WINTER_EXCEPTIONS_H

namespace mtm{
class Exception: public std::exception{
public:
Exception()= default;
~Exception()= default;
};


    class NegativeDays: public Exception{

    public:
      NegativeDays()=default;
      ~NegativeDays()=default;

    };

class InvalidStudent :public Exception{
public:
    InvalidStudent()= default;
    ~InvalidStudent()= default;

};

class AlreadyRegistered :public Exception{
public:
    AlreadyRegistered()= default;
    ~AlreadyRegistered()= default;
};

class RegistrationBlocked :public Exception{
public:
    RegistrationBlocked()= default;
    ~RegistrationBlocked()= default;

};
class NotRegistered: public Exception{
public:
    NotRegistered()= default;
    ~NotRegistered()= default;
};
class AlreadyInvited:public Exception{
public:
    AlreadyInvited()= default;
    ~AlreadyInvited()= default;
};
    class DateMismatch:public Exception{
    public:
        DateMismatch()= default;
        ~DateMismatch()= default;
    };

    class NotSupported:public Exception{
    public:
        NotSupported()= default;
        ~NotSupported()= default;
    };

    class  EventDoesNotExist:public Exception {
    public:
        EventDoesNotExist()= default;
        ~EventDoesNotExist()= default;
    };
   class EventAlreadyExists:public Exception{
   public:
       EventAlreadyExists()= default;
       ~EventAlreadyExists()= default;
   };
}
#endif //EX3_MTM_WINTER_EXCEPTIONS_H
