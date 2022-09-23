#include "testmodel.h"

testModel::testModel(int counter) : ID(counter)
{
    type_model = QString("NONE");
}


void testModel::onUpdate()
{
    emit this->modelUpdatedSignal(ID, this->type_model);
}

testModel::~testModel()
{

}
