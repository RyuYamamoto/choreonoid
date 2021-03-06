/**
   @file
   @author Shin'ichiro Nakaoka
*/

#ifndef CNOID_UTIL_MULTI_AFFINE3_SEQ_H_INCLUDED
#define CNOID_UTIL_MULTI_AFFINE3_SEQ_H_INCLUDED

#include "MultiSeq.h"
#include "EigenTypes.h"
#include "exportdecl.h"

namespace cnoid {

class Mapping;
class YAMLWriter;

class CNOID_EXPORT MultiAffine3Seq : public MultiSeq<Affine3, Eigen::aligned_allocator<Affine3> >
{
    typedef MultiSeq<Affine3, Eigen::aligned_allocator<Affine3> > BaseSeqType;

public:
    typedef boost::shared_ptr<MultiAffine3Seq> Ptr;

    MultiAffine3Seq();
    MultiAffine3Seq(int numFrames, int numParts = 1);
    MultiAffine3Seq(const MultiAffine3Seq& org);
    virtual ~MultiAffine3Seq();

    virtual AbstractSeqPtr cloneSeq() const;
        
    virtual bool loadPlainFormat(const std::string& filename);
    bool saveTopPartAsPlainFormat(const std::string& filename);

protected:
    virtual Affine3 defaultValue() const { return Affine3::Identity(); }

    virtual bool doWriteSeq(YAMLWriter& writer);
    virtual bool doReadSeq(const Mapping& archive);
};

typedef MultiAffine3Seq::Ptr MultiAffine3SeqPtr;        
}

#endif
