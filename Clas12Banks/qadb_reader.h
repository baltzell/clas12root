#ifndef QADB_READER_H
#define QADB_READER_H

#include "QADB.h"
#include <iostream>
#include <string>
#include <vector>

namespace clas12 {
  using std::string;
  
  class qadb_reader {

  public:

    qadb_reader(string jsonFilePath, int runNo);
    virtual ~qadb_reader()=default;  

    bool query(int runNb, int evNb){return _qa.Query(runNb,evNb);};
    int getFileNb(){return _qa.GetFilenum();};
    bool isGolden(){return _qa.Golden();};
    int getMinEventNb(){return _qa.GetEvnumMin();};
    int getMaxEventNb(){return _qa.GetEvnumMax();};
    int getDefect(){return _qa.GetDefect();};
    int getDefectForSector(int sector){return _qa.GetDefectForSector(sector);};
    bool hasDefect(const char * defectName, int sector){return _qa.HasDefect(defectName,sector);};
    bool hasDefect(const char * defectName){return _qa.HasDefect(defectName);};
    string getComment(){return _qa.GetComment();};

    bool isOkForAsymmetry(int runNb, int evNb){return _qa.OkForAsymmetry(runNb,evNb);};

    void addQARequirement(string req){_reqsQA.push_back(req);};
    void requireOkForAsymmetry(bool ok){_reqOKAsymmetry=ok;};
    void requireGolden(bool ok){_reqGolden=ok;};
    bool passQAReqs(int evNo);

  private: 

    QADB _qa;  
    std::vector<string> _reqsQA;
    bool _reqOKAsymmetry{false};
    bool _reqGolden{false};
    int _runNo{0};
    
  };

}
#endif /* QADB_READER_H */
