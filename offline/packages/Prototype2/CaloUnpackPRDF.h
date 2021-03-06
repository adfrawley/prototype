#ifndef PROTOTYPE2_CALOUNPACKPRDFF_H
#define PROTOTYPE2_CALOUNPACKPRDFF_H

//* Unpacks raw HCAL PRDF files *//
// Abhisek Sen

#include <fun4all/SubsysReco.h>

class Event;
class Packet_hbd_fpgashort;
class RawTowerContainer;

class CaloUnpackPRDF : public SubsysReco {
public:
  CaloUnpackPRDF();

  int Init(PHCompositeNode *topNode);

  int InitRun(PHCompositeNode *topNode);

  int process_event(PHCompositeNode *topNode);

  int End(PHCompositeNode *topNode);

  void CreateNodeTree(PHCompositeNode *topNode);

private:
  Event *_event;
  Packet_hbd_fpgashort *_packet;
  int _nevents;

  // HCAL node
  PHCompositeNode *dst_node;
  PHCompositeNode *data_node;

  // Towers
  RawTowerContainer *hcalin_towers_lg;
  RawTowerContainer *hcalout_towers_lg;

  RawTowerContainer *hcalin_towers_hg;
  RawTowerContainer *hcalout_towers_hg;

  RawTowerContainer *emcal_towers;
};

#endif
