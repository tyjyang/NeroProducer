#ifndef BARE_LEPTONS_H
#define BARE_LEPTONS_H

#include "NeroProducer/Core/interface/BareCollection.hpp"
#include "NeroProducer/Core/interface/BareP4.hpp"

class BareLeptons : virtual public BareP4
{
    public:
        enum Selection {
          LepVeto   = 1UL<<0,
          LepFake   = 1UL<<1,
          LepSoft   = 1UL<<2,
          LepLoose  = 1UL<<3,
          LepMedium = 1UL<<4,
          LepTight  = 1UL<<5
        };

        BareLeptons();
        ~BareLeptons();
        void init();
        void clear();
        void defineBranches(TTree *t);
        void setBranchAddresses(TTree*);
        virtual inline string name() { return "BareLeptons"; }

        bool inline passSelection(const unsigned &idx, const Selection &sel) const  { return (selBits->at(idx) & sel) != 0; }

        // ----
        vector<int>      *pdgId{0};	
        vector<float>    *iso{0};
        vector<unsigned> *selBits{0};
        vector<float>    *lepPfPt{0};

        vector<float>    *chIso{0};
        vector<float>    *nhIso{0};
        vector<float>    *phoIso{0};
        vector<float>    *puIso{0};
};

#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
