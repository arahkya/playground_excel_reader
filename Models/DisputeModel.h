#include <string>

#ifndef DISPUTEMODEL_H
#define DISPUTEMODEL_H
namespace Models
{
    class DisputeModel
    {
        private:
            std::string _createDate;
            std::string _branch;
            std::string _termId;
        public:
            std::string GetCreateDate() 
            {
                return _createDate;
            }
            std::string GetBranch()
            {
                return _branch;
            }
            std::string GetTermId()
            {
                return _termId;
            }
        DisputeModel(std::string createDate, std::string branch, std::string termId)
        {
            _createDate = createDate;
            _branch = branch;
            _termId = termId;
        }
    };
}
#endif