#ifndef OBJECTQUESTIONMARK_H
#define OBJECTQUESTIONMARK_H

#include "gameobject.h"

class ObjectQuestionMark : public GameObject
{
public:
    ObjectQuestionMark();
protected:
    bool checkInherited() override;
};

#endif // OBJECTQUESTIONMARK_H
