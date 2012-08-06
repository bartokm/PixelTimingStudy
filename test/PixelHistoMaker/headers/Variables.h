#include "TimingStudyCuts.h"

class Variables {
  
public:
  Variables() { 
    build_(); 
    init();
#ifndef VERSION1
    std::cout<<"Please #include Treereader before Variables"<<std::endl;
#endif
  }
  ~Variables() {}
  
  // run variables (read from file)
  std::map<int, double> totallumi;
  std::map<int, double> gaincorr_l1;
  std::map<int, double> gaincorr_l2;
  std::map<int, double> gaincorr_l3;
  float gc_l1;
  float gc_l2;
  float gc_l3;
  std::vector<std::vector<std::vector<int> > > goodroc_list; // VER2 >= 27
  int p1_filter; // dpeends on the number of file
  int modout; // dpeends on the number of file

  // lumi variables
  int    lumi_prescale;
  float  lumi_beamint;
  float  lumi_instlumi;
  double lumi_totlumi;
  double lumi_time;
  int p1_totlumi;
  float gaincorr;

  // lumi variables
  int lumi_nrun;
  std::vector<int> lumi_run;
  std::map<int, int> lumi_run2;
  std::map<unsigned long int, bool> run_ls;
  bool no_double_ls;
  std::map<int, std::string> lumi_fillname;
  std::map<int, int> lumi_firstrun;
  std::map<int, unsigned int> lumi_fillstart;
  std::vector<std::vector<int> > lumi_runs_in_fill;
  std::map<int, int> lumi_fill_index;
  int lumi_nfill;
  std::map<int, int> filldef;
  int lumi_fill;

  // evt variables
  int p1_evt_fillsch10;
  int p1_evt_fillsch11;
  int evt_run_binx;
  double evt_totlumi;  
  int evt_p1_fill;
  std::vector<int> evt_federr_type;
  std::vector<int> evt_federr_mult;
  int evt_fill;

  // traj variables
  int traj_det_x;
  int traj_lay_x;
  int traj_sdpx;
  int traj_mod_indexx;
  int traj_mod_indexy;
  int traj_mod_x;
  int traj_mod_y;
  int traj_mod_binx;
  int traj_mod_biny;
  int traj_mod2;
  int traj_shl;
  int traj_sec;
  int traj_roc;
  int p1_detshl;
  int p2_seclyrldr;
  int p2_dskbld;
  int p3_modroc;
  int p3_pnlplqroc;
  int p1_rocid;
  int p2_rocid;
  int p3_rocid;
  int p1_modid;
  int p2_modid;
  int p3_modid;
  int dcol_id;
  int traj_mod_p1;
  int traj_roc_p1;
  int traj_roc_binx;
  int traj_roc_biny;
  int traj_run_binx;
  int inac;
  int traj_nrun;
  std::vector<int> traj_run;
  float traj_gaincorr;
  int traj_isnewls;
  int p1_fill;
  int p1_fill2;
  int traj_p1_fill;
  std::vector<int> traj_evt_federr_type;
  int traj_evt_fill;
  int traj_newevt;
  int traj_occu[10];

  // Selections separately
  // Event Selections
  bool zb;
  bool nvtx;
  bool federr;
  // Track Selections
  bool hp;
  bool pt;
  bool nstrip;
  bool d0;
  bool dz;
  bool pixhit;
  // Module Exclusions
  bool noscan;
  bool goodmod;
  bool goodroc;
  // Module/ROC Fiducial Region Selections
  bool lx_fid;
  bool ly_fid;
  // Efficiency Related Selections
  bool valmis;
  bool hitsep;
  
  // Efficiency Cuts
  bool effcut_all;
  bool effcut_trig;
  bool effcut_nvtx;
  bool effcut_federr;
  bool effcut_raw;
  bool effcut_pt;
  bool effcut_nstrip;
  bool effcut_d0;
  bool effcut_dz;
  bool effcut_d0_dz;
  bool effcut_scans;
  bool effcut_ly_fid;
  bool effcut_lx_fid;
  bool effcut_lxly_fid;
  bool effcut_hitsep;

  // N-1
  int p1_fid;
  int p2_fid;
  // Effloss
  int p1_fillsch10;
  int p1_fillsch11;
  int p1_mod;
  int p2_lad;
  int p1_badcol;
  // Scans
  int delay;
  int p2_secdisk;
  int p3_layrog;
  int hv_x;
  int hv_p1;
  int hv_p2;
  int hv_bias;
  int hv_group;
  int hv_IO;
  int hv_l1_p1;
  int hv_l3_p1;
  int hv_d1_p1;
  int hv_l1full_p1;
  int hv_l2full_p1;
  int hv_l3full_p1;
  int hv_d1full_p1;
  int hv_d2full_p1;

  std::stringstream l1_col;
  std::stringstream l3_col;
  std::stringstream d1_col;
  std::stringstream l1full_col;
  std::stringstream l2full_col;
  std::stringstream l3full_col;
  std::stringstream d1full_col;
  std::stringstream d2full_col;
  std::vector<std::vector<double> > totlumi_scan;

  // Neweff
  float traj_dr_hit;

  // clust variables
  int clu_p1_rocid;
  int clu_p2_rocid;
  int clu_p3_rocid;
  int clu_evt_fill;
  int clu_p1_fill;
  int clu_det_x;
  int clu_lay_x;
  int clu_sdpx;
  int clu_mod_indexx;
  int clu_mod_indexy;
  int clu_mod_p1;
  int clu_roc_p1;
  int clu_roc_binx;
  int clu_roc_biny;

  // for binmaker
  int nx; 
  int ny;
  float xlow;
  float xup;
  float ylow;
  float yup;
  
 private:

  std::vector<int> npix_det_;
  std::vector<std::vector<std::vector<int> > > npix_mod_;

  std::vector<int> nclu_det_;
  std::vector<std::vector<std::vector<int> > > nclu_mod_;

  std::vector<std::vector<std::vector<std::vector<int> > > > roc_occupancy_list;
  std::vector<std::vector<std::vector<std::vector<std::vector<int> > > > > dcol_occupancy_list;

  int lumi_runcheck_;
  int traj_evt_runcheck_;
  int traj_evt_lscheck_;
  int traj_evt_fillcheck_;
  int evt_fillcheck_;
  int lumi_fillcheck_;
  int traj_evt_evtcheck_;

  int clu_evt_fillcheck_;

  int debug_;

  void build_() {
    debug_ = 0;
    npix_det_.resize(10);
    npix_mod_.resize(5);
    nclu_det_.resize(10);
    nclu_mod_.resize(5);
    for (int i=0; i<5; i++) npix_mod_[i].resize(9); 
    for (int i=0; i<9; i++) {
      for (int j=0; j<21; j++) npix_mod_[0][i].push_back(0);
      for (int j=0; j<33; j++) npix_mod_[1][i].push_back(0);
      for (int j=0; j<45; j++) npix_mod_[2][i].push_back(0);
      for (int j=0; j<48; j++) { npix_mod_[3][i].push_back(0); npix_mod_[4][i].push_back(0); }
    }
    for (int i=0; i<5; i++) nclu_mod_[i].resize(9);
    for (int i=0; i<9; i++) {
      for (int j=0; j<21; j++) nclu_mod_[0][i].push_back(0);
      for (int j=0; j<33; j++) nclu_mod_[1][i].push_back(0);
      for (int j=0; j<45; j++) nclu_mod_[2][i].push_back(0);
      for (int j=0; j<48; j++) { nclu_mod_[3][i].push_back(0); nclu_mod_[4][i].push_back(0); }
    }
    // Read Integrated Luminosity values for 2011 runs
    // Calculate total integrated luminosity for all runs
    int run;
    double intlumi = 0.0;
    double total = 0.0;
    FILE *input;
    input = fopen ("input/total_intlumi_ub.txt","r");
    int a = 1;
    while (a==1) {
      a = fscanf (input, "%d", &run);
      a = fscanf (input, "%lf", &intlumi);
      if (a==1) {
	total += intlumi;
	totallumi[run] = total;
      }
    }
    fclose (input);
    // Read gain correction factors
    float l1; input = fopen ("input/gaincorr_l1.txt","r"); a = 1;
    while (a==1) { a = fscanf (input, "%d", &run); fscanf (input, "%f", &l1);
      if (a==1) { gaincorr_l1[run] = l1; } }
    fclose (input);
    float l2; input = fopen ("input/gaincorr_l2.txt","r"); a = 1;
    while (a==1) { a = fscanf (input, "%d", &run); fscanf (input, "%f", &l2);
      if (a==1) { gaincorr_l2[run] = l2; } }
    fclose (input);
    float l3; input = fopen ("input/gaincorr_l3.txt","r"); a = 1;
    while (a==1) { a = fscanf (input, "%d", &run); fscanf (input, "%f", &l3);
      if (a==1) { gaincorr_l3[run] = l3; } }
    fclose (input);
    // create correct size of array matching ROC-IDs
    goodroc_list.resize(8);
    for (size_t i=0; i<8; i++) {
      if (i<4) { goodroc_list[i].resize(48);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(64);
      } else { goodroc_list[i].resize(24);
	for (size_t j=0; j<goodroc_list[i].size(); j++) goodroc_list[i][j].resize(45);
      }
    }
    roc_occupancy_list.resize(2); // 0: clu, 1: npix
    dcol_occupancy_list.resize(2); // 0: clu, 1: npix
    for (int i=0; i<2; i++) {
      roc_occupancy_list[i].resize(8);
      dcol_occupancy_list[i].resize(8);
      for (size_t j=0; j<8; j++) {
	if (j<4) { 
	  roc_occupancy_list[i][j].resize(48);
	  dcol_occupancy_list[i][j].resize(48);
	  for (size_t k=0; k<roc_occupancy_list[i][j].size(); k++) {
	    roc_occupancy_list[i][j][k].resize(64);
	    dcol_occupancy_list[i][j][k].resize(64);
	    for (size_t l=0; l<roc_occupancy_list[i][j][k].size(); l++)
	      dcol_occupancy_list[i][j][k][l].resize(26);
	  }
	} else { 
	  roc_occupancy_list[i][j].resize(24);
	  dcol_occupancy_list[i][j].resize(24);
	  for (size_t k=0; k<roc_occupancy_list[i][j].size(); k++) {
	    roc_occupancy_list[i][j][k].resize(45);
	    dcol_occupancy_list[i][j][k].resize(45);
	    for (size_t l=0; l<roc_occupancy_list[i][j][k].size(); l++)
	      dcol_occupancy_list[i][j][k][l].resize(26);
	  }
	}
      }
    }
    traj_evt_federr_type.resize(18);
    traj_evt_federr_type[0]=1;
    evt_federr_type.resize(18);
    evt_federr_mult.resize(18);
    evt_federr_type[0]=1;
    evt_federr_mult[0]=1;
    lumi_nfill = 0;
  }

  int voltage_(const EventData &evt, const ModuleData &mod_on) {
    int voltage = NOVAL_I;
    // hv scan 2010 April 05 - L3,FPix modules
    if (evt.run==132599||evt.run==132601||evt.run==132602) {
      if (evt.run==132599) {
        if (evt.ls>=1 && evt.ls<75) { voltage = (mod_on.det) ? 300 : 150;
        } else if (evt.ls>=75 && evt.ls<126) { voltage = (mod_on.det) ? 250 : 140;
        } else if (evt.ls>=126 && evt.ls<178) { voltage = (mod_on.det) ? 200 : 130;
        } else if (evt.ls>=178 && evt.ls<233) { voltage = (mod_on.det) ? 150 : 120;
        } else if (evt.ls>=233 && evt.ls<283) { voltage = (mod_on.det) ? 110 : 110;
        } else if (evt.ls>=283 && evt.ls<332) { voltage = (mod_on.det) ? 100 : 100;
        } else if (evt.ls>=332 && evt.ls<385) { voltage = (mod_on.det) ? 90 : 90;
        } else if (evt.ls>=385 && evt.ls<999) { voltage = (mod_on.det) ? 80 : 80;
        } else { voltage =NOVAL_I; }
      } else if (evt.run==132601) {
        if (evt.ls>=1 && evt.ls<50) { voltage = (mod_on.det) ? 70 : 70;
        } else if (evt.ls>=50 && evt.ls<105) { voltage = (mod_on.det) ? 60 : 60;
        } else if (evt.ls>=105 && evt.ls<155) { voltage = (mod_on.det) ? 50 : 50;
        } else if (evt.ls>=155 && evt.ls<207) { voltage = (mod_on.det) ? 40 : 40;
        } else if (evt.ls>=207 && evt.ls<258) { voltage = (mod_on.det) ? 30 : 30;
        } else { voltage =NOVAL_I; }
      }
      else voltage = (mod_on.det) ? 300 : 150;
    }
    // hv scan 2010 Oct 28 - L1,L2,FPix modules
    else if (evt.run==149182) {
      if (evt.ls<16) { voltage = (mod_on.det) ? 200 : 130;
      } else if (evt.ls>=17 && evt.ls<30) { voltage = (mod_on.det) ? 130 : 110;
      } else if (evt.ls>=30 && evt.ls<47) { voltage = 100;
      } else if (evt.ls>=47 && evt.ls<64) { voltage = 90;
      } else if (evt.ls>=64 && evt.ls<81) { voltage = 80;
      } else if (evt.ls>=81 && evt.ls<98) { voltage = 70;
      } else if (evt.ls>=98 && evt.ls<115) { voltage = 60;
      } else if (evt.ls>=115 && evt.ls<134) { voltage = 50;
      } else if (evt.ls>=134 && evt.ls<150) { voltage = 40;
      } else if (evt.ls>=150 && evt.ls<169) { voltage = 30;
      } else if (evt.ls>169) { voltage = (mod_on.det) ? 300 : 150; }
    }
    // hv scan 2011 March 14,16,18 - L1,L2,FPix modules
    else if (evt.run==160431||evt.run==160578||evt.run==160579||evt.run==160819||evt.run==160827||evt.run==160835) {
      if (evt.run==160579) {
	if (evt.orb<10060929) voltage = (mod_on.det) ? 30 : 40;
	else if (evt.orb>=10060929&&evt.orb<20603100) voltage = (mod_on.det) ? 35 : 50;
	else if (evt.orb>=20603100&&evt.orb<30368455) voltage = (mod_on.det) ? 40 : 60;
	else if (evt.orb>=30368455&&evt.orb<36726096) voltage = (mod_on.det) ? 50 : 70;
	else if (evt.orb>=36726096&&evt.orb<41127055) voltage = (mod_on.det) ? 60 : 80;
        else if (evt.orb>=41127055) voltage = (mod_on.det) ? 70 : 90;
      }
      else if (evt.run==160578) {
        if (evt.orb>=108617422) voltage = (mod_on.det) ? 20 : 30;
	else voltage = NOVAL_I;
      } 
      else if (evt.run==160819) {
        if (evt.orb<734481) voltage = NOVAL_I;
	else if (evt.orb>=734481&&evt.orb<4945473) voltage = (mod_on.det) ? 300 : 150;
	else if (evt.orb>=4945473&&evt.orb<9184218) voltage = (mod_on.det) ? 50 : 70;
        else if (evt.orb>=9184218&&evt.orb<13531251) voltage = (mod_on.det) ? 60 : 80;
        else if (evt.orb>=13531251&&evt.orb<21375662) voltage = (mod_on.det) ? 70 : 90;
        else if (evt.orb>=21375662&&evt.orb<27850887) voltage = (mod_on.det) ? 80 : 100;
        else voltage = NOVAL_I;
      }
      else if (evt.run==160827) voltage = (mod_on.det) ? 120 : 130;
      else if (evt.run==160835) {
        if (evt.orb<22377196) voltage = (mod_on.det) ? 120 : 150;
        else voltage = (mod_on.det) ? 300 : 150;
      }
      else if (evt.run==160431) voltage = (mod_on.det) ? 300 : 150;
    }
    // hv scan 2011 may 15 - Bpix_BmO_SEC6_LYR1-2_HV1
    // Run 165098,165099 - Bpix_BmO_SEC6_LYR1-2_HV1
    else if (evt.run==165098||evt.run==165099) {
      if (evt.run==165098) {
	if (evt.ls<169) voltage = 150;
	else if (evt.ls<235) voltage = 60;
	else if (evt.ls<302) voltage = 50;
	else if (evt.ls<379) voltage = 70;
	else voltage = 40;
      } else {
	if (evt.ls<33) voltage = 40;
	else voltage = 80;
      }
    }
    // voltage scan 2011 July 14 - L1
    else if (evt.run==170000) {
      if (evt.orb>=75305&&evt.orb<6600594) voltage = 150;
      else if (evt.orb>=6600594&&evt.orb<13798045) voltage = 20;
      else if (evt.orb>=13798045&&evt.orb<20548946) voltage = 30;
      else if (evt.orb>=20548946&&evt.orb<27295775) voltage = 40;
      else if (evt.orb>=27295775&&evt.orb<34043021) voltage = 50;
      else if (evt.orb>=34043021&&evt.orb<40787479) voltage = 60;
      else if (evt.orb>=40787479&&evt.orb<47534688) voltage = 70;
      else if (evt.orb>=47534688&&evt.orb<54281248) voltage = 80;
      else if (evt.orb>=54281248&&evt.orb<61029618) voltage = 90;
      else if (evt.orb>=61029618&&evt.orb<67777302) voltage = 100;
      else if (evt.orb>=67777302) voltage = 110;
      else voltage = NOVAL_I;
    } 
    // voltage scan 2011 July 28 - L3
    else if (evt.run==171897) {
      if (evt.orb<6600000) voltage = NOVAL_I;
      else if (evt.orb>=6600000&&evt.orb<13600000) voltage = 70;
      else if (evt.orb>=13600000&&evt.orb<20400000) voltage = 60;
      else if (evt.orb>=20400000&&evt.orb<27200000) voltage = 50;
      else if (evt.orb>=27200000&&evt.orb<33900000) voltage = 40;
      else if (evt.orb>=33900000&&evt.orb<40800000) voltage = 30;
      else if (evt.orb>=40800000&&evt.orb<47500000) voltage = 20;
      else if (evt.orb>=47500000&&evt.orb<54100000) voltage = 80;
      else if (evt.orb>=54100000) voltage = 150;
    } 
    // voltage scan 2011 Aug 03 - L2
    else if (evt.run==172488) {
      if (evt.orb<14400000) voltage = NOVAL_I;
      else if (evt.orb>=14400000&&evt.orb<17500000) voltage = 80;
      else if (evt.orb>=17500000&&evt.orb<20900000) voltage = 50;
      else if (evt.orb>=20900000&&evt.orb<24200000) voltage = 20;
      else if (evt.orb>=24200000&&evt.orb<27600000) voltage = 70;
      else if (evt.orb>=27600000&&evt.orb<31100000) voltage = 40;
      else if (evt.orb>=31100000&&evt.orb<34500000) voltage = 60;
      else if (evt.orb>=34500000&&evt.orb<39600000) voltage = 30;
      else if (evt.orb>=39600000) voltage = 150;
    } 
    // voltage scan 2011 Sep 07 - L1, FPix module
    else if (evt.run==175834) {
      // L1 scan
      if (evt.orb<38300000) {
        if (evt.orb<4600000) voltage = 150;
        else if (evt.orb<8000000) voltage = 100;
        else if (evt.orb<11400000) voltage = 80;
        else if (evt.orb<14800000) voltage = 70;
        else if (evt.orb<18200000) voltage = 60;
        else if (evt.orb<21600000) voltage = 50;
        else if (evt.orb<25000000) voltage = 40;
        else if (evt.orb<28300000) voltage = 30;
        else if (evt.orb<31600000) voltage = 20;
        else if (evt.orb<35000000) voltage = 10;
	else voltage = 0;
      }
      // FPix scan
      else if (evt.orb>70200000&&evt.orb<108800000) {
	if (evt.orb<75800000) voltage = 150;
        else if (evt.orb<79200000) voltage = 80;
        else if (evt.orb<82500000) voltage = 70;
        else if (evt.orb<86000000) voltage = 60;
        else if (evt.orb<89300000) voltage = 50;
        else if (evt.orb<92500000) voltage = 40;
        else if (evt.orb<98500000) voltage = 30;
        else if (evt.orb<101900000) voltage = 20;
        else if (evt.orb<105300000) voltage = 10;
        else voltage = 0;
      }
      else voltage = NOVAL_I;
    }
    // voltage scan 2011 Oct 12 - L1 module
    else if (evt.run==178367) {
      // L1 scan
      if (evt.orb<102930200) {
	if (evt.orb<22121144) voltage = 150;
	else if (evt.orb<28980545) voltage = 130;
	else if (evt.orb<35632848) voltage = 110;
	else if (evt.orb<42301525) voltage = 90;
	else if (evt.orb<49144222) voltage = 80;
	else if (evt.orb<55705743) voltage = 70;
	else if (evt.orb<62453171) voltage = 60;
	else if (evt.orb<69382373) voltage = 50;
	else if (evt.orb<75990540) voltage = 40;
	else if (evt.orb<82987680) voltage = 30;
	else if (evt.orb<89595172) voltage = 20;
	else if (evt.orb<96264991) voltage = 10;
	else voltage = 0;
      } else voltage = NOVAL_I;
    }
    // voltage scan 2011 Oct 27 - L1 module
    else if (evt.run==180076||evt.run==180093) {
      if (evt.run==180076) {
	if (evt.orb<65271702) voltage = 150;
	else if (evt.orb<69554218) voltage = 100;
	else if (evt.orb<75434312) voltage = 70;
	else if (evt.orb<79819278) voltage = 50;
	else if (evt.orb<85070175) voltage = 40;
	else if (evt.orb<89517576) voltage = 30;
	else voltage = 20;
      } else {
	if (evt.orb<3257552) voltage = 20;
	else if (evt.orb<7805011) voltage = 15;
	else if (evt.orb<11807013) voltage = 10;
	else if (evt.orb<16433020) voltage = 5;
	else if (evt.orb<21057541) voltage = 0;
	else if (evt.orb>22826117) voltage = 150;
	else voltage = NOVAL_I;
      }
    }
    // voltage scan 2011 Oct 30 - FPix module
    else if (evt.run==180241||evt.run==180250) {
      if (evt.run==180241) {
	if (evt.orb<99822153) voltage = 300;
	else if (evt.orb<103299446) voltage = 150;
	else if (evt.orb<106987682) voltage = 100;
	else voltage = 70;
      } else if (evt.run==180250&&evt.orb>15726839) {
	if (evt.orb<19447884) voltage = 70;
	else if (evt.orb<23554126) voltage = 50;
	else if (evt.orb<27501036) voltage = 40;
	else if (evt.orb<31867338) voltage = 30;
	else if (evt.orb<34939336) voltage = 20;
	else if (evt.orb<38504259) voltage = 15;
	else if (evt.orb<42213474) voltage = 10;
	else if (evt.orb<45793856) voltage = 5;
	else if (evt.orb<51126926) voltage = 0;
	else voltage = 150;
      } else voltage = NOVAL_I;
    }
    return voltage;
  }

 public:
  // binmaker for fiducial bin declarations
  void binmaker(int nroclx, int nrocly) {
    //     float rocsizelx = 0.8;
    //     float rocsizely = 0.8;
    //     int nbinslx = 32;
    //     int noutlx = 8;
    //     int nbinsly = 32;
    //     int noutly = 32;
    //     if (nroclx==1&&nrocly==8) {
    //       nbinslx = 16;
    //       noutlx = 4;
    //       nbinsly = 16;
    //       noutly = 16;
    //     }
    float rocsizelx = 0.8164;
    float rocsizely = 0.81;
    int nbinslx = 40;
    int noutlx = 10;
    int nbinsly = 26;
    int noutly = 26;
    if (nroclx==1&&nrocly==8) {
      nbinslx = 20;
      noutlx = 5;
      nbinsly = 13;
      noutly = 13;
    }
    nx = (nrocly * nbinsly + 2 * noutly);
    ny = (nroclx * nbinslx + 2 * noutlx);
    xlow = -1.0 * nx / 2 * rocsizely / nbinsly;
    xup = 1.0 * nx / 2 * rocsizely / nbinsly;
    ylow = -1.0 * ny / 2 * rocsizelx / nbinslx;
    yup = 1.0 * ny / 2 * rocsizelx / nbinslx;
  }
  
  void load_roc_sel_(int fill) {
    for (size_t i=0; i<8; i++) for (size_t j=0; j<goodroc_list[i].size(); j++)
      for (size_t k=0; k<goodroc_list[i][j].size(); k++) goodroc_list[i][j][k]=1;
    if (fill!=-1) {
      FILE *input;
      std::stringstream ss;
      ss<<"input/BADROC_EXCL/"
	<<lumi_fillname[fill]<<".txt";
      input = fopen(ss.str().c_str(),"r");
      if (input==0) {
	std::cout<<"No Bad ROC List exists for Fill "<<lumi_fillname[fill]<<std::endl;
      } else {
	int a=1;
	while (a==1) { int p1,p2,p3;
	  a = fscanf (input, "%d", &p1); a = a* fscanf (input, "%d", &p2);
	  a = a* fscanf (input, "%d", &p3); if (a==1) { goodroc_list[p1][p2][p3] = 0; }
	}
	fclose(input);
      }
    }
  }
  
  // Modifiers
  void load_lumi_var(const LumiData &lumi) {
#if VERSION2 < 29
    lumi_prescale = lumi.prescale[0]; // index not yet understood
#endif
    lumi_instlumi = lumi.instlumi; // (/ub)
#if VERSION2 >= 23
    lumi_beamint = (lumi.beamint[0] + lumi.beamint[1]) / 2.0;
#else
    lumi_beamint = NOVAL_F;
#endif
    // Fill number redefinition (to account for RAW problem and older versions)
    if (filldef.count(lumi.run)) lumi_fill = filldef[lumi.run];
    else { std::cout<<"Problem with filldef with run "<<lumi.run<<std::endl; lumi_fill = -1; }
#if VERSION2 >= 27
    lumi_time = (lumi.time - lumi_fillstart[lumi_fill])/3600.0;
#else
    lumi_time = (((lumi.run>=176201&&lumi.run<=176207) ? (lumi.run>176201)*666 + (lumi.run>176202)*301 + (lumi.run>176206)*109
		  : (lumi.run>=176304&&lumi.run<=176309) ? (lumi.run>176304)*619.2 + (lumi.run>176308)*308 : 0) + lumi.ls)* 23.3112 / 3600.0;
#endif
    // Calculate total luminosity (/pb)
    // Commented part doesn't work atm (intlumi values are random - can be negative)
    // can be replaced with ~23s * instlumi, then accumulate up to current ls
    int r = lumi.run;
    if ((totallumi.count(r))) lumi_totlumi = totallumi[r]/1000000.0;
    else if (r>132440) { while(!(totallumi.count(r))) r--; lumi_totlumi = totallumi[r]/1000000.0; }
    else if (r==NOVAL_I) { if (!debug_) std::cout<<"lumi.run = NOVAL_I"<<r<<std::endl; debug_++; lumi_totlumi = NOVAL_F; }
    else { std::cout<<"Warning: Early run before 132440 Run = "<<r<<std::endl; lumi_totlumi = NOVAL_F; }
    p1_totlumi = (lumi_totlumi<100) ? 0 
      : (lumi_totlumi>1300&&lumi_totlumi<=1500) ? 1
      : (lumi_totlumi>2600&&lumi_totlumi<=2800) ? 2
      : (lumi_totlumi>5500&&lumi_totlumi<=6177) ? 3
      : (lumi_totlumi>6177&&lumi_totlumi<=10000) ? 4
      : -1;
    // int r = lumi.run-1;
    // if ((totallumi.count(r))) lumi_totlumi = (totallumi[r] + lumi.intlumi/10.0)/1000000.0;
    // else {
    //   if (r>160404) {
    // 	while(!(totallumi.count(r))) r--;
    // 	lumi_totlumi = (totallumi[r] + lumi.intlumi/10.0)/1000000.0;
    //   } else if (r==160403) {
    // 	lumi_totlumi = lumi.intlumi/10000000.0;
    //   } else {
    // 	std::cout<<"Warning: 2010 run (before 160404)"<<std::endl;
    // 	lumi_totlumi = NOVAL_F; {
    // 	}
    //   }
    // }

    // Gain Correction Factor
    r = lumi.run;
    if ((gaincorr_l1.count(r))) gc_l1 = gaincorr_l1[r];
    else if (r>160955) { while(!(gaincorr_l1.count(r))) r--; gc_l1 = gaincorr_l1[r];
    } else gc_l1 = 1.0;
    if ((gaincorr_l2.count(r))) gc_l2 = gaincorr_l2[r];
    else if (r>160955) { while(!(gaincorr_l2.count(r))) r--; gc_l2 = gaincorr_l2[r];
    } else gc_l2 = 1.0;
    if ((gaincorr_l3.count(r))) gc_l3 = gaincorr_l3[r];
    else if (r>160955) { while(!(gaincorr_l3.count(r))) r--; gc_l3 = gaincorr_l3[r];
    } else gc_l3 = 1.0;
    gaincorr = (p1_totlumi==0) ? 1.0
      : (p1_totlumi==1) ? 21.8488/20.3201
      : (p1_totlumi==2) ? 22.0131/20.3201
      : (p1_totlumi==3) ? 22.2947/20.3201
      : 1;
    
    // Load new ROC selection
    if (lumi_fill!=lumi_fillcheck_) load_roc_sel_(lumi_fill);
    lumi_fillcheck_ = lumi_fill;
    if (lumi_fill==-1) std::cout<<"run not defined as any fill: "<<lumi.run<<std::endl;

    // Look for double LumiSection
    unsigned long int runls = lumi.run * 100000 + lumi.ls;
    if (run_ls.count(runls)==0) no_double_ls = true;
    else no_double_ls = false;
    run_ls[runls]=false;
  }

  void load_evt_var(const EventData &e) {
    // Run
    evt_run_binx = lumi_run2.count(e.run) ? lumi_run2[e.run] : NOVAL_I;
    // Calculate total luminosity (/pb)
    // Commented part doesn't work atm (intlumi values are random - can be negative)
    // can be replaced with ~23s * instlumi, then accumulate up to current ls
    int r = e.run;
    if ((totallumi.count(r))) evt_totlumi = totallumi[r]/1000000.0;
    else if (r>160404) { while(!(totallumi.count(r))) r--; evt_totlumi = totallumi[r]/1000000.0; }
    else { std::cout<<"Warning: 2010 run (before 160404)"<<std::endl; evt_totlumi = NOVAL_F; }
    // int r = e.run-1;
    // if ((totallumi.count(r))) evt_totlumi = (totallumi[r] + lumi.intlumi/10.0)/1000000.0;
    // else {
    //   if (r>160404) {
    //     while(!(totallumi.count(r))) r--;
    //     lumi_totlumi = (totallumi[r] + lumi.intlumi/10.0)/1000000.0;
    //   } else if (r==160403) {
    //     lumi_totlumi = lumi.intlumi/10000000.0;
    //   } else {
    //     std::cout<<"Warning: 2010 run (before 160404)"<<std::endl;
    //     lumi_totlumi = NOVAL_F; {
    //     }
    //   }
    // }

    // Fill 
    // Warning: evt_p1_fill depends on evt_fill
    if (filldef.count(e.run)) evt_fill = filldef[e.run];
    else { std::cout<<"Problem with filldef with run "<<e.run<<std::endl; evt_fill = -1; }
    if (evt_fill!=evt_fillcheck_) evt_p1_fill = lumi_fill_index[evt_fill];
    evt_fillcheck_ = evt_fill;

    // Fed error variable: tells the number of errors of a certain type in the event
    for (int i=1; i<18; i++) evt_federr_mult[i]=0;
    evt_federr_mult[1]=(e.federrs_size==0);
    evt_federr_mult[2]=e.federrs_size;
    for (int i=0; i<e.federrs_size; i++)
      evt_federr_mult[e.federrs[i][1]-22] += 1;
    // Fed error variable: tells whether event has certain FED error
    for (int i=1; i<18; i++) evt_federr_type[i]=0;
    evt_federr_type[1]=(e.federrs_size==0);
    evt_federr_type[2]=(e.federrs_size>0);
    for (int i=0; i<e.federrs_size; i++)
      evt_federr_type[e.federrs[i][1]-22] = 1;
  }

  int roc_(const float &lx, const float &ly, const ModuleData &m) {
    if (m.det==0) {
      if (fabs(ly)<3.24&&((m.half==0&&fabs(lx)<0.8164)||(m.half==1&&fabs(lx)<0.4082))) {
	int ny = (int)(ly / 0.81 + 4);
	int roc = (m.half) ? ((m.module<0)*8+ny) : ((m.module>0) ? ((lx>0.0) ? ny : 15-ny) : ((lx>0.0) ? 8+ny : 7-ny));
	return roc;
      } else return NOVAL_I;
    } else if (m.det==1) {
      int nrocly = m.module + m.panel;
      if (fabs(ly)<(nrocly*0.405) && ( ( !(m.panel==1&&(m.module==1||m.module==4)) && fabs(lx)<0.8164 ) || (fabs(lx)<0.4082) )) {
	int rocy = (int)((ly+(nrocly%2)*0.405)/0.81+nrocly/2);
	int roc = ((m.panel==2 && lx<0.0)
		   || (m.panel==1 && (m.module==1||m.module==4))
		   || (m.panel==1 && (m.module==2||m.module==3) && lx>0.0 )) ? rocy
	  : 2*nrocly -1 - rocy;
	return roc;
      } else return NOVAL_I;
    } else return NOVAL_I;
  }

  int clu_roc_(const float &x, const float &y, const ModuleData &m) {
    if (x!=NOVAL_F&&y!=NOVAL_F) {
      if (m.det==0) {
	int ny = (int)(y / 52.0);
	int roc = (m.half) ? ((m.module<0)*8+ny) : ((m.module>0) ? ((x>80.0) ? ny : 15-ny) : ((x>80.0) ? 8+ny : 7-ny));
	return roc;
      } else if (m.det==1) {
	int nrocly = m.module + m.panel;
	int rocy = (int)(y/52.0);
	int roc = ((m.panel==2 && x<80.0)
		   || (m.panel==1 && (m.module==1||m.module==4))
		   || (m.panel==1 && (m.module==2||m.module==3) && x>80.0 )) ? rocy
	  : 2*nrocly -1 - rocy;
	return roc;
      } else return NOVAL_I;
    } else {
      if (!debug_) std::cout<<"TReereader error: Please SetBrancStatus On"
			    <<" for branch: clust_xy in clustTree"<<std::endl;
      debug_++;
      return NOVAL_I;
    }
  }

  int roc2_(const float x, const float y, const ModuleData &m) {
    if (m.det==0) { // Barrel pixel
      int ny = (int)(y / 52); // Nth ROC along local y
      int roc = (m.half) ? ((m.module<0)*8+ny) // Half modules (Ladder +-1 etc)
	: ((m.module>0) ? ((x>80.0) ? ny // +Z (BpI,BpO), TBM A
			   : 15-ny ) // +Z, TBM B
	   : ((x>80.0) ? 8+ny  // -Z (BmI,BmO), TBM B
	      : 7-ny)); // -Z, TBM A
      return roc;
    } else if (m.det==1) { // Forward pixel
      int nroc = m.module + m.panel; // Number of Rocs along local y coordinate
      int ny = (int)(y / 52.0); // Nth ROC along local y
      int roc = ((m.panel==2 && x<80.0) // -ly side of 2xN Panel 2 Plaquettes
		 || (m.panel==1 && (m.module==1||m.module==4)) // 1x2, 1x5 Plaquettes on Panel 1
		 || (m.panel==1 && (m.module==2||m.module==3) && x>80.0 )) ? ny // +ly side of 2xN Panel 1 Plaquettes
	: 2*nroc -1 - ny; // Opposite side of 2xN Plaquettes
      return roc;
    } else return NOVAL_I;
  }

  void load_traj_var(const EventData &e, const TrajMeasurement &t) {
    if (!FILLS) p1_totlumi = 0;

    traj_dr_hit = (t.dx_hit!=NOVAL_F) ? sqrt(t.dx_hit*t.dx_hit+t.dy_hit*t.dy_hit) : NOVAL_F;
    traj_gaincorr = (t.mod_on.det) ? 1.0 : (t.mod_on.layer==1) ? gc_l1 
      : (t.mod_on.layer==2) ? gc_l2 : gc_l3;
    inac = (t.validhit!=1&&t.missing!=1);

    //________________________________________________________________________________________
    //                                    Event variables
    
    // Event
    traj_newevt = (e.evt!=traj_evt_evtcheck_);
    // if (traj_newevt) { // Do on every new event
    //   for (int i=1; i<18; i++) traj_evt_federr_type[i]=0;
    //   traj_evt_federr_type[1]=(e.federrs_size==0);
    //   traj_evt_federr_type[2]=(e.federrs_size!=0);
    //   for (int i=0; i<e.federrs_size; i++)
    //     traj_evt_federr_type[e.federrs[i][1]-22] = 1;
    // }
    traj_evt_evtcheck_=e.evt;
    // LumiSection
    traj_isnewls = (traj_evt_lscheck_!=e.ls);
    traj_evt_lscheck_ = e.ls;

    // Run
    if (e.run!=traj_evt_runcheck_) { 
      traj_nrun++;
      traj_run.push_back(e.run);
      traj_run_binx = 0;
      if ((lumi_run2.count(e.run))) traj_run_binx = lumi_run2[e.run];
    }
    traj_evt_runcheck_ = e.run;

    // Fill
    traj_evt_fill = filldef[e.run];
    if (traj_evt_fill!=traj_evt_fillcheck_) { 
      traj_p1_fill = lumi_fill_index[traj_evt_fill];
    }
    if (!FILLS) traj_p1_fill = NOVAL_I;
    traj_evt_fillcheck_ = traj_evt_fill;

#if VERSION1 > 29
    // Occupancy
    if (traj_newevt) {
      for (int i=0; i<10; i++) traj_occu[i]=0;
      traj_occu[0] += e.npix[0] + e.npix[1] + e.npix[2] + e.npix[3];
      traj_occu[1] += e.npix[1] + e.npix[2] + e.npix[3];
      traj_occu[2] += e.npix[0];
      traj_occu[3] += e.npix[1];
      traj_occu[4] += e.npix[2];
      traj_occu[5] += e.npix[3];
    }
#endif
    
    //________________________________________________________________________________________
    //                                   Geometry variables

    // Detector and layer number
    traj_det_x = t.mod_on.det + 1;
    traj_lay_x = (t.mod_on.det==0) ? t.mod_on.layer :  t.mod_on.disk + 5 + (t.mod_on.disk<0);
    p1_fid = traj_lay_x - 1;

    // Shell
    traj_shl = (t.mod_on.det==0) ? 2 * (t.mod_on.module<0) + (t.mod_on.ladder<0)
      : 2 * (t.mod_on.disk<0) + (t.mod_on.blade<0);

    // Sector
    int lad = abs(t.mod_on.ladder);
    traj_sec = (t.mod_on.det) ? NOVAL_I : (t.mod_on.layer==1) ? lad - 1 + (lad==1) - (lad==10) 
      : (t.mod_on.layer==2) ? (lad+1)/2 : (lad+2+(lad>11)*2)/3;

    // Side-Disk-Panel number - similar to module_on.module
    traj_sdpx = ((t.mod_on.disk>0) ? 1 : -1) * (2 * (abs(t.mod_on.disk) - 1) + t.mod_on.panel);

    // Ladder
    p2_lad = (t.mod_on.ladder+t.mod_on.layer * 6 + 4 - (t.mod_on.ladder>0));

    // Module number
    traj_mod_indexx = ((t.mod_on.det) ? traj_sdpx : t.mod_on.module) + 4;
    traj_mod_indexy = (t.mod_on.det) ? ((t.mod_on.blade>0) ? t.mod_on.blade-1 : t.mod_on.blade + 12)*4 +
      + t.mod_on.module-1 : t.mod_on.layer * 6 + 4 + t.mod_on.ladder;
    traj_mod_x = (t.mod_on.det) ? traj_sdpx : t.mod_on.module;
    traj_mod_y = (t.mod_on.det) ? t.mod_on.blade : t.mod_on.ladder;
    p1_mod = t.mod_on.module + 4 - (t.mod_on.module>0);
    traj_mod2 = abs(t.mod_on.module);
    p2_fid = (t.mod_on.det==0) ? t.mod_on.half : t.mod_on.module -1 + 4*(t.mod_on.panel-1);

    // Specific Modules with Bad Columns
    p1_badcol = (t.mod_on.layer==1) ? ((  t.mod_on.ladder== 6 &&t.mod_on.module==1) ? 0
					      : (t.mod_on.ladder==-2 &&t.mod_on.module==1) ? 1
					      : (t.mod_on.ladder==-4 &&t.mod_on.module==2) ? 2
					      : (t.mod_on.ladder== 4 &&t.mod_on.module==-2) ? 3
					      : (t.mod_on.ladder== 5 &&t.mod_on.module==-2) ? 4
					      : (t.mod_on.ladder==-1 &&t.mod_on.module==-1) ? 5 : NOVAL_I)
      : (t.mod_on.layer==2) ? ((  t.mod_on.ladder== 12 &&t.mod_on.module==3) ? 6
				      : (t.mod_on.ladder== 14 &&t.mod_on.module==1) ? 7
				      : (t.mod_on.ladder== 16 &&t.mod_on.module==1) ? 8
				      : (t.mod_on.ladder== -2 &&t.mod_on.module==1) ? 9
				      : (t.mod_on.ladder== -3 &&t.mod_on.module==3) ? 10
				      : (t.mod_on.ladder== -5 &&t.mod_on.module==1) ? 11
				      : (t.mod_on.ladder==  7 &&t.mod_on.module==-1) ? 12
				      : (t.mod_on.ladder==-13 &&t.mod_on.module==-2) ? 13
				      : (t.mod_on.ladder==-15 &&t.mod_on.module==-2) ? 14
				      : (t.mod_on.ladder==-16 &&t.mod_on.module==-1) ? 15 : NOVAL_I)
      : (t.mod_on.layer==3) ? ((  t.mod_on.ladder== 19 &&t.mod_on.module==1) ? 16
				      : (t.mod_on.ladder== -3 &&t.mod_on.module==2) ? 17
				      : (t.mod_on.ladder== -6 &&t.mod_on.module==2) ? 18
				      : (t.mod_on.ladder==-13 &&t.mod_on.module==1) ? 19
				      : (t.mod_on.ladder==-19 &&t.mod_on.module==3) ? 20
				      : (t.mod_on.ladder== -5 &&t.mod_on.module==-1) ? 21
				      : (t.mod_on.ladder== -6 &&t.mod_on.module==-1) ? 22
				      : (t.mod_on.ladder== -8 &&t.mod_on.module==-1) ? 23 : NOVAL_I) : NOVAL_I;

    // Select which histogram does the module/roc belong to
    traj_mod_p1 = (t.mod_on.det) ? 3 : t.mod_on.layer - 1;
    traj_roc_p1 = (t.mod_on.det) ? ((t.mod_on.blade>0) ? 3 : 4 ) : t.mod_on.layer - 1;

    // ROC number
    traj_roc = roc_(t.lx, t.ly, t.mod_on) ;
    // Module/ROC online format: BPix_BmI_SEC7_LYR1_LDR8F_MOD2_ROC0 / FPix_BmI_D1_BLD1_PNL2_PLQ2_ROC0
    // BPix - [Det][Shl][Sec][Lyr][Ldr][MOD][ROC] --> [Det-Shl][Sec-Lyr-Ldr][Mod-Roc] (gap on half modules)
    // FPix - [Det][Shl][Dsk][Bld][Pnl][PLQ][ROC] --> [Det_Shl][Dsk-Bld][Pnl-Plq-Roc] (no gap)
    p1_detshl = t.mod_on.det*4 + traj_shl;
    p2_seclyrldr = (t.mod_on.det==0) ? lad-1 + (t.mod_on.layer>1)*10 + (t.mod_on.layer>2)*16 : NOVAL_I;
    p3_modroc = (t.mod_on.det==0) ? (abs(t.mod_on.module)-1)*16 + traj_roc : NOVAL_I;
    p2_dskbld = (t.mod_on.det==1) ? (abs(t.mod_on.disk)-1)*12 + abs(t.mod_on.blade)-1 : NOVAL_I;
    p3_pnlplqroc = (t.mod_on.det==1) ? ((t.mod_on.panel==1) ? (t.mod_on.module>1)*2 + (t.mod_on.module>2)*6 + (t.mod_on.module>3)*8
					: 21 + (t.mod_on.module>1)*6 + (t.mod_on.module>2)*8) + traj_roc : NOVAL_I;

    p1_rocid = p1_detshl;
    p2_rocid = (t.mod_on.det) ? p2_dskbld : p2_seclyrldr;
    p3_rocid = (t.mod_on.det) ? p3_pnlplqroc : p3_modroc;

    p1_modid = p1_rocid;
    p2_modid = p2_rocid;
    p3_modid = (t.mod_on.det==0) ? abs(t.mod_on.module)-1 : t.mod_on.module-1 + (t.mod_on.panel>1)*4;

    dcol_id = int(fmod(t.ly+(t.mod_on.det==1&&(t.mod_on.panel+t.mod_on.module)%2==1)*0.405+3.24,0.81)/0.81*26);

    // Roc BinX number for ROC map plots (traj branch)
    traj_roc_binx = NOVAL_I;
    if (t.mod_on.det==0) {
      traj_roc_binx = (fabs(t.ly)<3.24) ? (int)((t.mod_on.module+4)*8 - t.ly / 0.81 + 5)  : NOVAL_I;
    } else if (t.mod_on.det==1) {
      // Roc is left (0) or right (1) on the ROC map plot (+Z side)
      int binselx = (t.mod_on.panel==1&&(t.mod_on.module==1||t.mod_on.module==4)) ?
        ((fabs(t.lx)<0.4082) ? (t.mod_on.module==1) : NOVAL_I ) 
        : ((fabs(t.lx)<0.8164) ? ((t.mod_on.panel==1&&t.lx<0.0)||(t.mod_on.panel==2&&t.lx>=0.0)) : NOVAL_I);
      // Gives the Roc location inside a panel (0 to 5 on +Z side)
      int nperpan = 2 * t.mod_on.module + t.mod_on.panel - 1 + binselx;
      traj_roc_binx = (binselx!=NOVAL_I) ? ((t.mod_on.disk>0) ? nperpan : 9 - nperpan) + (traj_sdpx + 4) * 8 
        - 2 * ((abs(t.mod_on.disk)==1) ? t.mod_on.disk : 0) : NOVAL_I;
    }
    // Roc BinY number for ROC map plots (traj branch)
    traj_roc_biny = NOVAL_I;
    if (t.mod_on.det==0) {
      if ((t.mod_on.half==0&&fabs(t.lx)<0.8164)||(t.mod_on.half==1&&fabs(t.lx)<0.4082)) {
        // Roc is in bottom (0) or top bin (1) inside a ladder on th ROC map plot
        int binsely = ((t.mod_on.half==1&&((t.mod_on.ladder<0&&t.mod_on.ladder%2==0)||t.mod_on.ladder%2==1))
		       ||(t.mod_on.half==0&&((t.mod_on.ladder<0 &&((t.mod_on.ladder%2==-1&&t.lx<0.0)
								   ||(t.mod_on.ladder%2==0&&t.lx>0.0)))
					     ||(t.mod_on.ladder>0 &&((t.mod_on.ladder%2==0&&t.lx<0.0)
								     ||(t.mod_on.ladder%2==1&&t.lx>0.0))))));
	traj_roc_biny = (t.mod_on.layer * 6 + t.mod_on.ladder + 4) * 2 + 1 + binsely;
      }
    } else if (t.mod_on.det==1) {
      // Gives the number of ROCs along ly
      int nrocly = t.mod_on.module + t.mod_on.panel;
      if (fabs(t.ly)<(nrocly*0.405)) {
	int rocy = (int)((t.ly+(nrocly%2)*0.405)/0.81+nrocly/2);
	traj_roc_biny = 7 - nrocly + 2 * ((t.mod_on.disk<0) ? rocy : nrocly - 1 - rocy) 
	  + (t.mod_on.blade-1 + (t.mod_on.blade<0)*13)*12;
      }
    }

    //________________________________________________________________________________________
    //                                     Scan variables

    // Delay Scan - 2011
    delay = e.run==160413 ? 
      (e.orb   <  11531874 ?  25
       : e.orb <  22836667 ?   0
       : e.orb <  36525473 ? NOVAL_I // BAD
       : e.orb <  47699601 ?   7 
       : e.orb <  60471838 ?   8
       : e.orb <  71445138 ?  10
       : e.orb <  84930036 ? -25
       : e.orb < 100147197 ? NOVAL_I // BAD
       : e.orb < 114600000 ?  14
       : e.orb < 129039651 ?  16
       : e.orb < 145100000 ? -12
       : e.orb < 160586081 ?  10
       : e.orb < 174462084 ?  -6
       : e.orb < 191550000 ?  -8
       : 12
       ) : 
      e.run==160497 ? 
      (e.orb   < 11923615 ? NOVAL_I
       : e.orb < 23009846 ? -4
       : e.orb < 34154357 ? -2
       : NOVAL_I // BAD
       ) : 
      e.run==160577 ?
      (e.orb   < 10359519 ? NOVAL_I
       : e.orb < 26677701 ? 4
       : e.orb < 40220000 ? 18
       : e.orb < 53440000 ? 20
       : e.orb < 66319978 ? 22
       : 14
       ) :
      e.run==160578 ?
      (e.orb   <   1245694 ? NOVAL_I
       : e.orb <  14309529 ? 14
       : e.orb <  43223561 ? 16
       : e.orb <  71862094 ? 15
       : e.orb < 108617422 ? 13
       : NOVAL_I
       ) :
      // 2012 - April
      e.run==190411 ? 
      ( e.ls <  26 ?  13 :
	e.ls <  44 ?  -6 :
	e.ls <  63 ? -12 :
	e.ls <  80 ? -18 :
	e.ls <  94 ?   6 :
	e.ls < 108 ?  12 :
	e.ls < 127 ?  NOVAL_I :
	e.ls < 150 ?  13 :
	e.ls < 175 ?  14 :
	e.ls < 196 ?  15 :
	e.ls < 214 ?  16 :
	e.ls < 230 ?  12 :
	e.ls < 246 ?  17 :
	e.ls < 261 ?  18 :
	e.ls < 277 ?  20 :
	e.ls < 292 ?   0 :
	e.ls < 309 ?  -2 :
	-4 ) :
      e.run==190456 ? 
      ( e.ls <  70  ?  13 :
	e.ls <  88  ?   2 :
	e.ls < 108  ?   6 :
	e.ls < 132  ?  10 :
	e.ls < 149  ?  11 :
	e.ls < 164  ?  38 :
	e.ls < 174  ? -12 :
	NOVAL_I ) :
      // 2012 - July
      // New Vana Settings
      e.run==198022 ?
      ( e.orb < 47500000 ? NOVAL_I : 
	e.orb < 49500000 ? 13 :
	e.orb < 53000000 ?  1 :
	e.orb < 56500000 ? 24 :
	e.orb < 60000000 ? 22 :
	20 ) :
      e.run==198023 ? 
      ( e.orb <  4906628 ? 18 :
	e.orb <  9006831 ? 16 :
	e.orb < 12767345 ? 14 :
	e.orb < 16996865 ? 12 :
	e.orb < 21167493 ? 10 :
	e.orb < 25000000 ?  8:
	NOVAL_I ) :
      // Old Vana Settings
      e.run==198048 ? 
      ( e.orb <  2600000 ?  1 :
	e.orb <  5600000 ? 24 :
	e.orb <  8600000 ? 22 :
	e.orb < 12000000 ? 20 :
	e.orb < 15200000 ? 18 :
	16 ) :
      NOVAL_I;
    
    // ROG variables
    p2_secdisk = (t.mod_on.det==0) ? traj_sec - 1 : 7 + abs(t.mod_on.disk) ;
    p3_layrog = (t.mod_on.det==0) ? (t.mod_on.layer==3) : (abs(t.mod_on.blade)-1)/3;
    // HV Scans
    hv_x = voltage_(e, t.mod_on);

    hv_IO = (t.mod_on.det==1) ? ((t.mod_on.panel==1) ? t.mod_on.module>2 : t.mod_on.module>1 ) : NOVAL_I; // 0: inner, 1: outer
    hv_group = (t.mod_on.det==1) ? (abs(t.mod_on.blade)+2)/3 : NOVAL_I; // Same as Readout group

    hv_p1 = (e.run==132599||e.run==132601||e.run==132602) ? 0 : // 2010 April 05
      (e.run==149182) ? 1 : // 2010 Oct 28
      (e.run==160431||e.run==160578||e.run==160579||
       e.run==160819||e.run==160827||e.run==160835) ? 2 : // 2011 March 14,16,18
      (e.run==165098||e.run==165099) ? 3 : // 2011 May 15
      (e.run==170000) ? 4 : // 2011 July 14
      (e.run==171897) ? 5 : // 2011 July 28
      (e.run==172488) ? 6 : // 2011 August 03
      (e.run==175834) ? 7 : // 2011 September 07
      (e.run==178367) ? 8 : // 2011 October 12
      (e.run==180076||e.run==180093) ? 9 : // 2011 October 27
      (e.run==180241||e.run==180250) ? 10 : // 2011 October 30
      (e.run==190538||e.run==190539||e.run==190591||
       e.run==190592||e.run==190593||e.run==190595) ? 11 : // 2012 April 06
      (e.run==198023||e.run==198041||e.run==198044||e.run==198045) ? 12 : // 2012 July 02
      NOVAL_I;
    hv_p2 = 
      (hv_p1==0) ? ( (t.mod_on.disk==-1  && hv_group==1 && hv_IO==0 ) ? 0
		     : (t.mod_on.layer==3 && t.mod_on.module>0 && t.mod_on.ladder<0 && traj_sec==2) ? 1 : NOVAL_I ) :
      (hv_p1==1) ? ( ( t.mod_on.disk==-1  && hv_group==1 && hv_IO==0 ) ? 0
		     : (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==2) ? 1
		     : (t.mod_on.layer==3 && t.mod_on.module>0 && t.mod_on.ladder<0 && traj_sec==2) ? 2 : NOVAL_I ) :
      (hv_p1==2) ? ( (t.mod_on.disk==-1  && hv_group==1 && hv_IO==0) ? 0
		     : (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==6) ? 1
		     : (t.mod_on.layer==3 && t.mod_on.module>0 && t.mod_on.ladder<0 && traj_sec==2) ? 2 : NOVAL_I ) :
      (hv_p1==3) ? ( (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==6) ? 0 : NOVAL_I ) :
      (hv_p1==4) ? ( (t.mod_on.layer==1) ? 0 : NOVAL_I ) :
      (hv_p1==5) ? ( (t.mod_on.layer==3) ? 0 : NOVAL_I ) :
      (hv_p1==6) ? ( (t.mod_on.layer==2) ? 0 : NOVAL_I ) :
      (hv_p1==7) ? ( ( t.mod_on.disk==-1 && hv_group==1 && hv_IO==0 && e.orb>70200000 && e.orb<108800000 ) ? 0 :
		     ( t.mod_on.layer==1 && e.orb<38300000)   ? 1 : NOVAL_I ) :
      (hv_p1==8) ? ( (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==6) ? 0 : NOVAL_I ) :
      (hv_p1==9) ? ( (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==6) ? 0 : NOVAL_I ) :
      (hv_p1==10) ? ( (t.mod_on.disk==-1  && hv_group==1 && hv_IO==0 ) ? 0 : NOVAL_I ) :
      (hv_p1==11) ? ( (t.mod_on.layer==1)     ? ( (e.run==190538||(e.run==190539&&e.ls<89)) ? 0 : NOVAL_I ) :
		      (t.mod_on.layer==2)     ? ( (e.run==190539&&e.ls>=91&&e.ls<261) ? 1 : NOVAL_I) :
		      (t.mod_on.layer==3)     ? ( ((e.run==190539&&e.ls>=261)||(e.run==190591&&e.ls<186)) ? 2 : NOVAL_I) :
		      (abs(t.mod_on.disk)==1) ? ( ((e.run==190591&&e.ls>=201)||e.run==190592||e.run==190593||(e.run==190595&&e.ls<107)) ? 3 : NOVAL_I) :
		      (abs(t.mod_on.disk)==2) ? ( (e.run==190595&&e.ls>=107) ? 4 : NOVAL_I): NOVAL_I ) :
      (hv_p1==12) ? ( (t.mod_on.layer==1)     ? ( ((e.run==198023&&e.orb>=26472615)||(e.run==198041&&e.orb<2562384)) ? 0 : NOVAL_I ) :
		      (t.mod_on.layer==2)     ? ( ((e.run==198041&&e.orb>=2562384)||(e.run==198044&&e.orb<12662468)) ? 1 : NOVAL_I) :
		      (t.mod_on.layer==3)     ? ( ((e.run==198044&&e.orb>=12662468)||(e.run==198045&&e.orb<20579655)) ? 2 : NOVAL_I) :
		      (abs(t.mod_on.disk)==1) ? ( (e.run==198045&&e.orb>=20579655&&e.orb<43564392) ? 3 : NOVAL_I) :
		      (abs(t.mod_on.disk)==2) ? ( (e.run==198045&&e.orb>=43564392) ? 4 : NOVAL_I): NOVAL_I ) :
      NOVAL_I;
    
    hv_l1_p1     = (hv_p1!=NOVAL_I) ? ( (t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==2) ? 
					( hv_p1==   1 ? 0 : NOVAL_I) :
					(t.mod_on.layer==1 && t.mod_on.module<0 && t.mod_on.ladder<0 && traj_sec==6) ?
					( hv_p1 ==  2 ? 1 :
					  hv_p1 ==  3 ? 2 :
					  hv_p1 ==  4 ? 3 :
					  hv_p1 ==  7 && e.orb<38300000 ? 4 :
					  hv_p1 ==  8 ? 5 :
					  hv_p1 ==  9 ? 6 :
					  hv_p1 == 11 && (e.run==190538||(e.run==190539&&e.ls<89)) ? 7 :
					  hv_p1 == 12 && (e.run==198023||(e.run==198041&&e.orb<2562384)) ? 8 :
					  NOVAL_I 
					  ) : NOVAL_I 
					) : NOVAL_I;
    hv_l3_p1     = (hv_p1!=NOVAL_I) ? ( (t.mod_on.layer==3 && t.mod_on.module>0 && t.mod_on.ladder<0 && traj_sec==2) ?
					( hv_p1 ==  0 ? 0 :
					  hv_p1 ==  1 ? 1 :
					  hv_p1 ==  2 ? 2 :
					  hv_p1 ==  5 ? 3 :
					  hv_p1 == 11 && ((e.run==190539&&e.ls>=261)||(e.run==190591&&e.ls<186)) ? 4 :
					  hv_p1 == 12 && ((e.run==198044&&e.orb>12662468)||(e.run==198045&&e.orb<20579655)) ? 5 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_d1_p1     = (hv_p1!=NOVAL_I) ? ( (t.mod_on.disk==-1 && hv_group==1 && hv_IO==0) ?
					( hv_p1 ==  0 ? 0 :
					  hv_p1 ==  1 ? 1 :
					  hv_p1 ==  2 ? 2 :
					  hv_p1 ==  7 && e.orb>70200000&&e.orb<108800000 ? 3 :
					  hv_p1 == 10 ? 4 :
					  hv_p1 == 11 && ((e.run==190591&&e.ls>=201)||e.run==190592||e.run==190593||(e.run==190595&&e.ls<107)) ? 5 :
					  hv_p1 == 12 && ((e.run==198045&&e.orb>20579655&&e.orb<43564392)) ? 6 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_l1full_p1 = (hv_p1!=NOVAL_I) ? ( (t.mod_on.layer==1) ?
					( hv_p1 ==  4 ? 0 :
					  hv_p1 ==  7 ? 1 :
					  hv_p1 == 11 && (e.run==190538||(e.run==190539&&e.ls<89)) ? 2 :
					  hv_p1 == 12 && (e.run==198023||(e.run==198041&&e.orb<2562384)) ? 3 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_l2full_p1 = (hv_p1!=NOVAL_I) ? ( (t.mod_on.layer==2) ?
					( hv_p1 ==  6 ? 0 :
					  hv_p1 == 11 && (e.run==190539&&e.ls>=91&&e.ls<261) ? 1 : 
					  hv_p1 == 12 && ((e.run==198041&&e.orb>=2562384)||(e.run==198044&&e.orb<12662468)) ? 2 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_l3full_p1 = (hv_p1!=NOVAL_I) ? ( (t.mod_on.layer==3) ?
					( hv_p1 ==  5 ? 0 :
					  hv_p1 == 11 && ((e.run==190539&&e.ls>=261)||(e.run==190591&&e.ls<186)) ? 1 :
					  hv_p1 == 12 && ((e.run==198044&&e.orb>12662468)||(e.run==198045&&e.orb<20579655)) ? 2 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_d1full_p1 = (hv_p1!=NOVAL_I) ? ( abs(t.mod_on.disk)==1 ?
					( hv_p1 == 11 && ((e.run==190591&&e.ls>=201)||e.run==190592||e.run==190593||(e.run==190595&&e.ls<107)) ? 0 :
					  hv_p1 == 12 && ((e.run==198045&&e.orb>20579655&&e.orb<43564392)) ? 1 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;
    hv_d2full_p1 = (hv_p1!=NOVAL_I) ? ( abs(t.mod_on.disk)==2 ?
					( hv_p1 == 11 && (e.run==190595&&e.ls>=107) ? 0 :
					  hv_p1 == 12 && ((e.run==198045&&e.orb>43564392)) ? 1 :
					  NOVAL_I
					  ) : NOVAL_I
					) : NOVAL_I;

    hv_bias = 
      // hv scan 2010 April 05 - L3,FPix modules
      (e.run==132599||e.run==132601||e.run==132602) ?
      ( (e.run==132599) ? ( (e.ls< 75) ? ((t.mod_on.det) ? 300 : 150) :
			    (e.ls<126) ? ((t.mod_on.det) ? 250 : 140) :
			    (e.ls<178) ? ((t.mod_on.det) ? 200 : 130) :
			    (e.ls<233) ? ((t.mod_on.det) ? 150 : 120) :
			    (e.ls<283) ? ((t.mod_on.det) ? 110 : 110) :
			    (e.ls<332) ? ((t.mod_on.det) ? 100 : 100) :
			    (e.ls<385) ? ((t.mod_on.det) ?  90 :  90) :
			    (             (t.mod_on.det) ?  80 :  80) ) :
	(e.run==132601) ? ( (e.ls< 50) ? ((t.mod_on.det) ?  70 :  70) :
			    (e.ls<105) ? ((t.mod_on.det) ?  60 :  60) :
			    (e.ls<155) ? ((t.mod_on.det) ?  50 :  50) :
			    (e.ls<207) ? ((t.mod_on.det) ?  40 :  40) :
			    (e.ls<258) ? ((t.mod_on.det) ?  30 :  30) :
 			    (             NOVAL_I                   ) ) :
	(                                 (t.mod_on.det) ? 300 : 150) ) :
      // hv scan 2010 Oct 28 - L1,L2,FPix modules
      (e.run==149182) ? ( (e.ls< 16) ? ((t.mod_on.det) ? 200 : 130) :
			  (e.ls< 30) ? ((t.mod_on.det) ? 130 : 110) :
			  (e.ls< 47) ?  100 :
			  (e.ls< 64) ?   90 :
			  (e.ls< 81) ?   80 :
			  (e.ls< 98) ?   70 :
			  (e.ls<115) ?   60 :
			  (e.ls<134) ?   50 :
			  (e.ls<150) ?   40 :
			  (e.ls<169) ?   30 :
			  (             (t.mod_on.det) ? 300 : 150) ) :
      // hv scan 2011 March 14,16,18 - L1,L2,FPix modules
      (e.run==160431||e.run==160578||e.run==160579||e.run==160819||e.run==160827||e.run==160835) ?
      ( (e.run==160431) ? (                      (t.mod_on.det) ? 300 : 150) :
	(e.run==160578) ? ( (e.orb<108617422) ?  NOVAL_I :
			    (                    (t.mod_on.det) ?  20 :  30) ) :
	(e.run==160579) ? ( (e.orb< 10060929) ? ((t.mod_on.det) ?  30 :  40) :
			    (e.orb< 20603100) ? ((t.mod_on.det) ?  35 :  50) :
			    (e.orb< 30368455) ? ((t.mod_on.det) ?  40 :  60) :
			    (e.orb< 36726096) ? ((t.mod_on.det) ?  50 :  70) :
			    (e.orb< 41127055) ? ((t.mod_on.det) ?  60 :  80) :
			    (                    (t.mod_on.det) ?  70 :  90) ) :
	(e.run==160819) ? ( (e.orb<   734481) ?  NOVAL_I :
			    (e.orb<  4945473) ? ((t.mod_on.det) ? 300 : 150) :
			    (e.orb<  9184218) ? ((t.mod_on.det) ?  50 :  70) :
			    (e.orb< 13531251) ? ((t.mod_on.det) ?  60 :  80) :
			    (e.orb< 21375662) ? ((t.mod_on.det) ?  70 :  90) :
			    (e.orb< 27850887) ? ((t.mod_on.det) ?  80 : 100) :
			    (                    NOVAL_I                 ) ) :
	(e.run==160827) ? (                      (t.mod_on.det) ? 120 : 130) :
	(                   (e.orb< 22377196) ? ((t.mod_on.det) ? 120 : 150) :
			    (                    (t.mod_on.det) ? 300 : 150) ) ) :
      // hv scan 2011 may 15 - Bpix_BmO_SEC6_LYR1-2_HV1
      (e.run==165098||e.run==165099) ?
      ( (e.run==165098) ? ( (e.ls<169) ? 150 :
			    (e.ls<235) ?  60 :
			    (e.ls<302) ?  50 :
			    (e.ls<379) ?  70 :
			    (             40 ) ) : 
	(                   (e.ls< 33) ?  40 : 
			    (             80 ) ) ) :
      // voltage scan 2011 July 14 - L1
      (e.run==170000) ? ( (e.orb<   75305) ? NOVAL_I :
			  (e.orb< 6600594) ? 150 :
			  (e.orb<13798045) ?  20 :
			  (e.orb<20548946) ?  30 :
			  (e.orb<27295775) ?  40 :
			  (e.orb<34043021) ?  50 :
			  (e.orb<40787479) ?  60 :
			  (e.orb<47534688) ?  70 :
			  (e.orb<54281248) ?  80 :
			  (e.orb<61029618) ?  90 :
			  (e.orb<67777302) ? 100 :
			  (                  110 ) ) : 
      // voltage scan 2011 July 28 - L3
      (e.run==171897) ? ( (e.orb< 6600000) ?  NOVAL_I :
			  (e.orb<13600000) ?  70 :
			  (e.orb<20400000) ?  60 :
			  (e.orb<27200000) ?  50 :
			  (e.orb<33900000) ?  40 :
			  (e.orb<40800000) ?  30 :
			  (e.orb<47500000) ?  20 :
			  (e.orb<54100000) ?  80 :
			  (                  150 ) ) :
      // voltage scan 2011 Aug 03 - L2
      (e.run==172488) ? ( (e.orb<14400000) ?  NOVAL_I :
			  (e.orb<17500000) ?  80 :
			  (e.orb<20900000) ?  50 :
			  (e.orb<24200000) ?  20 :
			  (e.orb<27600000) ?  70 :
			  (e.orb<31100000) ?  40 :
			  (e.orb<34500000) ?  60 :
			  (e.orb<39600000) ?  30 :
			  (                  150 ) ) :
      // voltage scan 2011 Sep 07 - L1, FPix module
      (e.run==175834) ? (// L1 scan
			 (e.orb<38300000) ?
			 ( (e.orb< 4600000) ? 150 :
			   (e.orb< 8000000) ? 100 :
			   (e.orb<11400000) ?  80 :
			   (e.orb<14800000) ?  70 :
			   (e.orb<18200000) ?  60 :
			   (e.orb<21600000) ?  50 :
			   (e.orb<25000000) ?  40 :
			   (e.orb<28300000) ?  30 :
			   (e.orb<31600000) ?  20 :
			   (e.orb<35000000) ?  10 :
			   (                    0 ) ) :
			 // FPix scan
			 (e.orb>70200000&&e.orb<108800000) ?
			 ( (e.orb< 75800000) ? 150 :
			   (e.orb< 79200000) ?  80 :
			   (e.orb< 82500000) ?  70 :
			   (e.orb< 86000000) ?  60 :
			   (e.orb< 89300000) ?  50 :
			   (e.orb< 92500000) ?  40 :
			   (e.orb< 98500000) ?  30 :
			   (e.orb<101900000) ?  20 :
			   (e.orb<105300000) ?  10 :
			   (                     0 ) ) :
			 (                     NOVAL_I ) ) :
      // voltage scan 2011 Oct 12 - L1 module
      (e.run==178367) ? ( (e.orb<102930200) ?
			  ( (e.orb<22121144) ? 150 :
			    (e.orb<28980545) ? 130 :
			    (e.orb<35632848) ? 110 :
			    (e.orb<42301525) ?  90 :
			    (e.orb<49144222) ?  80 :
			    (e.orb<55705743) ?  70 :
			    (e.orb<62453171) ?  60 :
			    (e.orb<69382373) ?  50 :
			    (e.orb<75990540) ?  40 :
			    (e.orb<82987680) ?  30 :
			    (e.orb<89595172) ?  20 :
			    (e.orb<96264991) ?  10 :
			    (                    0 ) ) : 
			  (                    NOVAL_I ) ) :
      // voltage scan 2011 Oct 27 - L1 module
      (e.run==180076||e.run==180093) ?
      ( (e.run==180076) ? ( (e.orb<65271702) ? 150 :
			    (e.orb<69554218) ? 100 :
			    (e.orb<75434312) ?  70 :
			    (e.orb<79819278) ?  50 :
			    (e.orb<85070175) ?  40 :
			    (e.orb<89517576) ?  30 :
			    (                   20 ) ) : 
	(                   (e.orb< 3257552) ?  20 :
			    (e.orb< 7805011) ?  15 :
			    (e.orb<11807013) ?  10 :
			    (e.orb<16433020) ?   5 :
			    (e.orb<21057541) ?   0 :
			    (e.orb<22826117) ? NOVAL_I :
			    (                  150 ) ) ) :
      // voltage scan 2011 Oct 30 - FPix module
      (e.run==180241||e.run==180250) ?
      ( (e.run==180241) ? ( (e.orb< 99822153) ? 300 :
			    (e.orb<103299446) ? 150 :
			    (e.orb<106987682) ? 100 :
			    (                    70 ) ) :
	(e.run==180250&&e.orb>15726839) ?
	(                   (e.orb<19447884) ?  70 :
			    (e.orb<23554126) ?  50 :
			    (e.orb<27501036) ?  40 :
			    (e.orb<31867338) ?  30 :
			    (e.orb<34939336) ?  20 :
			    (e.orb<38504259) ?  15 :
			    (e.orb<42213474) ?  10 :
			    (e.orb<45793856) ?   5 :
			    (e.orb<51126926) ?   0 :
			    (                  150 ) ) :
	(                                      NOVAL_I ) ) :
      // voltage scan 2012 Apr 06 - L1, L2, L3, D1, D2
      (e.run==190538||e.run==190539||e.run==190591||e.run==190592||e.run==190593||e.run==190595) ?
      ( (e.run==190538) ? ( (e.ls< 50) ? 150 : // L1
			    (e.ls< 66) ?   0 :
			    (e.ls< 78) ?   5 :
			    (e.ls< 91) ?  10 :
			    (e.ls<104) ?  15 :
			    (e.ls<117) ?  20 :
			    (             30 ) ) :
	(e.run==190539) ? ( (e.ls<  3) ? NOVAL_I :
			    (e.ls< 17) ?  30 :
			    (e.ls< 30) ?  40 :
			    (e.ls< 47) ?  50 :
			    (e.ls< 62) ?  70 :
			    (e.ls< 75) ? 100 :
			    (e.ls< 91) ? 150 :
			    (e.ls<105) ?   0 : // L2
			    (e.ls<120) ?   5 :
			    (e.ls<135) ?  10 :
			    (e.ls<150) ?  15 :
			    (e.ls<165) ?  20 :
			    (e.ls<180) ?  30 :
			    (e.ls<196) ?  40 :
			    (e.ls<211) ?  50 :
			    (e.ls<225) ?  70 :
			    (e.ls<240) ? 100 :
			    (e.ls<263) ? 150 :
			    (e.ls<280) ?   0 : // L3
			    (e.ls<295) ?   5 :
			    (e.ls<315) ?  10 :
			    (e.ls<327) ?  15 :
			    (            NOVAL_I) ) :
	(e.run==190591) ? ( (e.ls< 87) ?  NOVAL_I :
			    (e.ls<104) ?  20 :
			    (e.ls<118) ?  30 :
			    (e.ls<134) ?  40 :
			    (e.ls<150) ?  50 :
			    (e.ls<163) ?  70 :
			    (e.ls<178) ? 100 :
			    (e.ls<191) ? 150 :
			    (e.ls<203) ?   0 : // D1
			    (              5 ) ) :
	(e.run==190592) ? ( (e.ls< 14) ?  10 :
			    (e.ls< 29) ?  15 :
			    (             20 ) ) :
	(e.run==190593) ? (               20 ) :
	(                   (e.ls< 16) ?  20 :
			    (e.ls< 30) ?  30 :
			    (e.ls< 43) ?  40 :
			    (e.ls< 56) ?  50 :
			    (e.ls< 69) ?  70 :
			    (e.ls< 82) ? 100 :
			    (e.ls< 95) ? 150 :
			    (e.ls<107) ? 300 :
			    (e.ls<119) ?   0 : // D2
			    (e.ls<132) ?   5 :
			    (e.ls<147) ?  10 :
			    (e.ls<161) ?  15 :
			    (e.ls<175) ?  20 :
			    (e.ls<187) ?  30 :
			    (e.ls<199) ?  40 :
			    (e.ls<210) ?  50 :
			    (e.ls<223) ?  70 :
			    (e.ls<237) ? 100 :
			    (e.ls<250) ? 150 :
			    (            300 ) ) ) :
      // voltage scan 2012 Jul 02 - L1, L2, L3, D1, D2
      (e.run==198023||e.run==198041||e.run==198044||e.run==198045) ?
      ( (e.run==198023) ? ( (e.orb<25000000) ? NOVAL_I : // L1
			    (e.orb<28800000) ? 150 :
			    (e.orb<30600000) ? 100 :
			    (e.orb<32800000) ?  80 :
			    (e.orb<35600000) ?  70 :
			    (e.orb<38200000) ?  60 :
			    (e.orb<39700000) ?  50 :
			    (e.orb<41100000) ?  40 :
			    (e.orb<42350000) ?  30 :
			    (e.orb<43900000) ?  20 :
			    (                   10 ) ) :
	(e.run==198041) ? ( (e.orb< 2600000) ?   5 :
			    (e.orb< 4700000) ? 150 : // L2
			    (e.orb< 6700000) ? 100 :
			    (e.orb< 8700000) ?  80 :
			    (e.orb<12100000) ?  70 :
			    (e.orb<14100000) ?  60 :
			    (                   50 ) ) :
	(e.run==198044) ? ( (e.orb< 1300000) ?  50 :
			    (e.orb< 4000000) ?  40 :
			    (e.orb< 6000000) ?  30 :
			    (e.orb< 8000000) ?  20 :
			    (e.orb<10700000) ?  10 :
			    (e.orb<12800000) ?   5 :
			    (e.orb<14800000) ? 150 : // L3
			    (                  100 ) ) :
	(                   (e.orb< 1200000) ? 100 :
			    (e.orb< 3200000) ?  80 :
			    (e.orb< 5800000) ?  70 :
			    (e.orb< 7900000) ?  60 :
			    (e.orb<10600000) ?  50 :
			    (e.orb<12600000) ?  40 :
			    (e.orb<14600000) ?  30 :
			    (e.orb<16700000) ?  20 :
			    (e.orb<18661675) ?  10 :
			    (e.orb<20700000) ?   5 :
			    (e.orb<23200000) ? 150 : // D1
			    (e.orb<25200000) ? 100 :
			    (e.orb<27200000) ?  80 :
			    (e.orb<29281687) ?  70 :
			    (e.orb<31300000) ?  60 :
			    (e.orb<33261006) ?  50 :
			    (e.orb<35400000) ?  40 :
			    (e.orb<37338482) ?  30 :
			    (e.orb<39418496) ?  20 :
			    (e.orb<41343074) ?  10 :
			    (e.orb<43500000) ?   5 :
			    (e.orb<45500000) ? 150 : // D2
			    (e.orb<47600000) ? 100 :
			    (e.orb<49650000) ?  80 :
			    (e.orb<51450000) ?  70 :
			    (e.orb<53550000) ?  60 :
			    (e.orb<55400000) ?  50 :
			    (e.orb<57450000) ?  40 :
			    (e.orb<59450000) ?  30 :
			    (e.orb<61500000) ?  20 :
			    (e.orb<63500000) ?  10 :
			    (e.orb<65600000) ?   5 :
			    (              NOVAL_I ) ) ) :
      NOVAL_I;
    
    //=========================================================================================
    //                                    Efficiency Cuts
    //=========================================================================================
    //__________________________________________________________________________________________
    //                                    Event Selections
    
    // ZeroBias trigger
    zb = e.trig >> 0 & 1;
    
    // Number of Primary Verices >= 1 (where VtxZ<20 cm, VtxD0 < 2 cm, VtxNdof > 4)
    nvtx = e.nvtx>=1;
    
    // No FED Error in the Event
    // Previous cut: t.mod_on.federr==0
    federr = e.federrs_size==0;
    
    //__________________________________________________________________________________________
    //                                    Track Selections
    
    // Track quality bit: HighPurity track
    hp = (t.trk.quality&4)!=0;
    
    // Hit originates from track with Pt > 1.0 GeV
    // Previous pt cuts:
    // BPix - 1.0 GeV, FPix 1.2 GeV
    // 0.6 GeV
    pt = t.trk.pt>1.0;
    
    // Number of hits in the Silicon Strip Tracker > 10
    nstrip = t.trk.strip>10;
    
    // Track Impact parameters (track to vertex D0/Z distance)
    d0 = t.mod_on.det==0 ?
      (t.mod_on.layer==1 ? fabs(t.trk.d0)<0.01 // L1
       : fabs(t.trk.d0)<0.02 ) // L2,3
      : t.mod_on.det==1 && fabs(t.trk.d0)<0.05; // FPix
    
    dz = (t.mod_on.det==0 && fabs(t.trk.dz)<0.1) 
      ||(t.mod_on.det==1 && fabs(t.trk.dz)<0.5);
    
    // Require 2 Valid hit on 2 other layer(s) and/or disk(s)
    pixhit = t.mod_on.det==0 ?
      ( // BPix
       t.mod_on.layer==1 ?
       (t.trk.validbpix[1]>0 && t.trk.validbpix[2]>0) // L2 + L3
       || (t.trk.validbpix[1]>0 && t.trk.validfpix[0]>0) // L2 + D1
       || (t.trk.validfpix[0]>0 && t.trk.validfpix[1]>0) // D1 + D2
       : t.mod_on.layer==2 ?
       (t.trk.validbpix[0]>0 && t.trk.validbpix[2]>0) // L1 + L3
       || (t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0) // L1 + D1
       : t.mod_on.layer==3 &&
       t.trk.validbpix[0]>0 && t.trk.validbpix[1]>0 ) // L1 + L2
      : t.mod_on.det==1 &&
      ( // FPix
       abs(t.mod_on.disk)==1 ?
       (t.trk.validbpix[0]>0 && t.trk.validfpix[1]>0) // L1 + D2
       || (t.trk.validbpix[1]>0 && t.trk.validfpix[1]>0) // or L2 + D2
       : abs(t.mod_on.disk)==2 &&
       t.trk.validbpix[0]>0 && t.trk.validfpix[0]>0 ); // L1 + D1
    
    //__________________________________________________________________________________________
    //                                 Bad Module/ROC Exclusions
    
    // Exclude Modules affected by Timing and HV Scans
    //   HV Scans
    //   Copy this from Variables!
    
    bool excl_hv = hv_p2==NOVAL_I||e.run==160431; // This run was not scanned
    
    // Delay Scans
    bool excl_delay =  !(e.run==160413||e.run==160497||e.run==160577||e.run==160578||e.run==170000)
      // One Module scanned (WBC scan)
      && !(t.mod_on.layer==2&&t.mod_on.ladder==-5&&t.mod_on.module==2&&(e.run==161310||e.run==161311));
    
    noscan = excl_hv && excl_delay;

    // Exclude some known bad modules
    goodmod = t.mod_on.det==0 ?
      ( // BPix
       t.mod_on.layer==1 ?
       !(t.mod_on.ladder==  4 && t.mod_on.module==-4 && t.lx>0.0)
       : t.mod_on.layer==2 ?
       !(t.mod_on.ladder== -8 && t.mod_on.module== 1 && t.lx>0.0) &&
       !(t.mod_on.ladder==-13 && t.mod_on.module== 3 && t.lx<0.0)
       : t.mod_on.layer==3 && 
       !(t.mod_on.ladder==14&&t.mod_on.module==-4&&e.run>=141956&&e.run<160404) &&
       !(e.run>=162713&&( (t.mod_on.ladder== 13 &&(t.mod_on.module==-1 || t.mod_on.module==-2 || t.mod_on.module==-3)) ||
			  (t.mod_on.ladder== 12 &&(t.mod_on.module==-1 || t.mod_on.module==-2)) ||
			  (t.mod_on.ladder==-17 && t.mod_on.module==-3) ) ) )
      : t.mod_on.det==1 &&
      ( // FPix
       t.mod_on.disk==-2 ?
       !(t.mod_on.blade==10 && t.mod_on.panel==1)
       : t.mod_on.disk==-1 ?
       !(t.mod_on.blade==6  && t.mod_on.panel==1)
       : t.mod_on.disk==1 ?
       !(e.run==146644&&( t.mod_on.blade==-1 || t.mod_on.blade==-2 || t.mod_on.blade==-3)) && // Whole ROG out
       !(e.run>=163655&&  t.mod_on.blade==-5 && t.mod_on.panel==2 && t.mod_on.module==2 ) // 4x2 PLQ problem
       : t.mod_on.disk==2 &&
       !(e.run>=147752&&( t.mod_on.blade== 4 || t.mod_on.blade== 5 || t.mod_on.blade== 6)) );
    
    // Good roc selecton
    goodroc = goodroc_list[p1_rocid][p2_rocid][p3_rocid];
    
    
    //__________________________________________________________________________________________
    //                          Module/ROC Fiducial Region Selections:
    //                       Cut on the local coordinates of a hit LX/LY
    //             Exclude Module/ROC edges and regions where nearby modules overlap
    
    // Module Edge Cut - LX
    bool edge_lx = t.mod_on.det==0 ? 
      ( // BPix
       t.mod_on.half==0 ? fabs(t.lx)<0.65
       : t.mod_on.half==1 && t.lx>-0.3 && t.lx<0.25 )
      : t.mod_on.det==1 &&
      ( // FPix
       t.mod_on.panel==1 ?
       ( // Panel 1
	t.mod_on.module== 1 ? t.lx>-0.15 && t.lx<0.3
	: t.mod_on.module==2 ? (abs(t.mod_on.disk)==1  ? t.lx>-0.55 && t.lx<0.6 :
				 abs(t.mod_on.disk)==2 && t.lx>-0.6 && t.lx<0.3)
	: t.mod_on.module==3 ? (abs(t.mod_on.disk)==1  ? t.lx> 0.3 && t.lx<0.6 :
				 abs(t.mod_on.disk)==2 && t.lx>-0.6 && t.lx<0.5)
	: t.mod_on.module==4 && t.lx>-0.3 && t.lx<0.15 )
       : t.mod_on.panel==2 &&
       ( // Panel 2
	t.mod_on.module==1 ? t.lx>-0.55 && t.lx<0.6
	: t.mod_on.module==2 ? (abs(t.mod_on.disk)==1  ? fabs(t.lx)<0.55 :
				 abs(t.mod_on.disk)==2 && t.lx>-0.6 && t.lx<0.55)
	: t.mod_on.module==3 && fabs(t.lx)<0.55) );
    
    // ROC Edge cut - LX
    bool rocedge_lx = !((t.mod_on.half==0||(t.mod_on.det==1&&!(t.mod_on.panel==1&&(t.mod_on.module==1||t.mod_on.module==4))))
			&& fabs(t.lx)<0.06);
    
    lx_fid = edge_lx && rocedge_lx;
    
    
    // Module Edge Cut - LY
    bool edge_ly = t.mod_on.det==0 ? fabs(t.ly)<3.1 // BPix
      : t.mod_on.det==1 &&
      ( // FPix
       t.mod_on.panel==1 ?
       ( // Panel 1
	t.mod_on.module==1 ? fabs(t.ly)<0.7
	: t.mod_on.module==2 ? fabs(t.ly)<1.1 
	&& !(t.mod_on.disk==-1 && t.lx>0.25 && t.ly> 0.75)
	&& !(t.mod_on.disk== 1 && t.lx>0.25 && t.ly<-0.75)
	: t.mod_on.module==3 ? fabs(t.ly)<1.5
	&& !(t.mod_on.disk==-1 && t.ly > 1.1)
	&& !(t.mod_on.disk== 1 && t.ly <-1.0)
	&& !(t.mod_on.disk==-2 && t.lx>0.15 && t.ly> 1.1)
	&& !(t.mod_on.disk== 2 && t.lx>0.15 && t.ly<-1.1)
	: t.mod_on.module==4 && fabs(t.ly)<1.9
	&& !(t.mod_on.disk==-2 && t.ly> 1.5)
	&& !(t.mod_on.disk== 2 && t.ly<-1.5) )
       : t.mod_on.panel==2 &&
       ( // Panel 2
	t.mod_on.module==1 ? fabs(t.ly)<0.7
	: t.mod_on.module==2 ? fabs(t.ly)<1.1
	: t.mod_on.module==3 && fabs(t.ly)<1.6
	&& !(t.mod_on.disk>0 && t.ly>1.5)
	&& !(t.mod_on.disk<0 && t.ly<-1.5) ) );
    
    // ROC Edge cut - LY
    float ly_mod = fabs(t.ly) + (t.mod_on.det==1&&(t.mod_on.panel+t.mod_on.module)%2==1)*0.405;
    float d_rocedge = fabs(fabs(fmod(ly_mod,0.81)-0.405)-0.405);
    bool rocedge_ly = d_rocedge > 0.06;
    
    ly_fid = edge_ly && rocedge_ly;
    
    //__________________________________________________________________________________________
    //                            Efficiency Related Selections
    
    // Valid or Missing hit (not Inactive, Invalid or Bad)
    // Previous: ( ( t.mod_on.layer==1&&t.lxmatch!=NOVAL_F ||t.mod_on.layer!=1 ) 
    //             &&t.validhit==1 ) || t.missing==1
    valmis = t.validhit==1||t.missing==1;
    
    // Nearest other hit is far away (D_hit > 0.5 cm)
#if VERSION1 >= 29
    hitsep = t.hit_near==0;
#else
    hitsep = t.dx_hit==NOVAL_F||sqrt(t.dx_hit*t.dx_hit+t.dy_hit*t.dy_hit)>0.5; 
#endif

//     bool Pixhit = pixhit || t.mod_on.det==1;

    //                zb,   nvtx,   federr,   hp,   pt,   nstrip,   d0,   dz,   pixhit,   noscan,   goodmod,   goodroc,   lx_fid,   ly_fid,   valmis,   hitsep
    effcut_all      =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod &&            lx_fid && ly_fid && valmis && hitsep;
    effcut_trig     =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_nvtx     =               federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_federr   =       nvtx &&           hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_pt       =       nvtx && federr && hp &&       nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_nstrip   =       nvtx && federr && hp && pt &&           d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_d0       =       nvtx && federr && hp && pt && nstrip &&       dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_dz       =       nvtx && federr && hp && pt && nstrip && d0 &&       pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_d0_dz    =       nvtx && federr && hp && pt && nstrip &&             pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis && hitsep;
    effcut_scans    =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit &&           goodmod &&            lx_fid && ly_fid && valmis && hitsep;
    effcut_raw      =       nvtx &&           hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod &&            lx_fid && ly_fid && valmis && hitsep;
    effcut_lx_fid   =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc &&           ly_fid && valmis && hitsep;
    effcut_ly_fid   =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid &&           valmis && hitsep;
    effcut_lxly_fid =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc &&                     valmis && hitsep;
    effcut_hitsep   =       nvtx && federr && hp && pt && nstrip && d0 && dz && pixhit && noscan && goodmod && goodroc && lx_fid && ly_fid && valmis          ;
    
    // float cut_rocedge = 0.0;
    // if (!((t.mod_on.half==0||(t.mod_on.det==1&&!(t.mod_on.panel==1&&(t.mod_on.module==1||t.mod_on.module==4))))
    //       && fabs(t.lx)<cut_rocedge)&&d_rocedge > cut_rocedge && edge_lx && edge_ly&&effcut_lxly_fid &&t.validhit==1) {
    //   int clust_roc = clu_roc_(t.clu.x, t.clu.y, t.mod_on);
    //   if (clust_roc!=traj_roc) {
    //     debug_++;
    //     if (debug_%100==0)
    //     std::cout<<debug_<<" "<<traj_roc<<" "<<clust_roc<<std::endl;
    //   }
    // }
  
  }

  void load_clu_var(const EventData &cluevt, const Cluster &clust) {

    //__________________________________________________________________________________________
    //                                   Geometry variables

    // Shell
    int shl = (clust.mod_on.det==0) ? 2 * (clust.mod_on.module<0) + (clust.mod_on.ladder<0)
      : 2 * (clust.mod_on.disk<0) + (clust.mod_on.blade<0);
    
    // Roc Number
    int clust_roc = clu_roc_(clust.x, clust.y, clust.mod_on);

    int clu_p1_detshl = clust.mod_on.det*4 + shl;
    int clu_p2_seclyrldr = (clust.mod_on.det==0) ? abs(clust.mod_on.ladder)-1 + (clust.mod_on.layer>1)*10 + (clust.mod_on.layer>2)*16 : NOVAL_I;
    int clu_p3_modroc = (clust.mod_on.det==0) ? (abs(clust.mod_on.module)-1)*16 + clust_roc : NOVAL_I;
    int clu_p2_dskbld = (clust.mod_on.det==1) ? (abs(clust.mod_on.disk)-1)*12 + abs(clust.mod_on.blade)-1 : NOVAL_I;
    int clu_p3_pnlplqroc = (clust.mod_on.det==1) ? ((clust.mod_on.panel==1) ? (clust.mod_on.module>1)*2 + (clust.mod_on.module>2)*6 + (clust.mod_on.module>3)*8
						    : 21 + (clust.mod_on.module>1)*6 + (clust.mod_on.module>2)*8) + clust_roc : NOVAL_I;
    
    clu_p1_rocid = clu_p1_detshl;
    clu_p2_rocid = (clust.mod_on.det) ? clu_p2_dskbld : clu_p2_seclyrldr;
    clu_p3_rocid = (clust.mod_on.det) ? clu_p3_pnlplqroc : clu_p3_modroc;
    
    //__________________________________________________________________________________________
    //                                        Other
    
    clu_evt_fill = filldef[cluevt.run];
    if (clu_evt_fill!=clu_evt_fillcheck_)
      clu_p1_fill = lumi_fill_index[clu_evt_fill];
    clu_evt_fillcheck_ = clu_evt_fill;
    // Detector and layer number
    clu_det_x = clust.mod_on.det + 1;
    clu_lay_x = (clust.mod_on.det==0) ? clust.mod_on.layer :  clust.mod_on.disk + 5 + (clust.mod_on.disk<0);
    // Side-Disk-Panel number - similar to module_on.module
    clu_sdpx = ((clust.mod_on.disk>0) ? 1 : -1) * (2 * (abs(clust.mod_on.disk) - 1) + clust.mod_on.panel);
    // Module number
    clu_mod_indexx = ((clust.mod_on.det) ? clu_sdpx : clust.mod_on.module) + 4;
    clu_mod_indexy = (clust.mod_on.det) ? ((clust.mod_on.blade>0) ? clust.mod_on.blade-1 : clust.mod_on.blade + 12)*4 +
      + clust.mod_on.module-1 : clust.mod_on.layer * 6 + 4 + clust.mod_on.ladder;
    // Select which histogram does the module/roc belong to
    clu_mod_p1 = (clust.mod_on.det) ? 3 : clust.mod_on.layer - 1;
    clu_roc_p1 = (clust.mod_on.det) ? ((clust.mod_on.blade>0) ? 3 : 4 ) : clust.mod_on.layer - 1;
    // Roc BinX number for ROC map plots (clust branch)
    clu_roc_binx = NOVAL_I;
    if (clust.mod_on.det==0) {
      for (int i=1;i<=8;i++) if (clust.y>=((8-i)*52.0)&&clust.y<((9-i)*52.0))
        clu_roc_binx = (clust.mod_on.module+4)*8 + i;
    } else if (clust.mod_on.det==1) {
      // Roc is left (0) or right (1) on the ROC map plot (+Z side)
      int binselx = (clust.mod_on.panel==1&&(clust.mod_on.module==1||clust.mod_on.module==4)) ? (clust.mod_on.module==1)
        : ((clust.mod_on.panel==1&&clust.x<80.0)||(clust.mod_on.panel==2&&clust.x>=80.0));
      // Gives the Roc location inside a panel (0 to 5 on +Z side)
      int nperpan = 2 * clust.mod_on.module + clust.mod_on.panel - 1 + binselx;
      clu_roc_binx = ((clust.mod_on.disk>0) ? nperpan : 9 - nperpan) + (clu_sdpx + 4) * 8 
        - 2 * ((abs(clust.mod_on.disk)==1) ? clust.mod_on.disk : 0);
    }
    // Roc BinY number for ROC map plots (clust branch)
    clu_roc_biny = NOVAL_I; 
    if (clust.mod_on.det==0) {
      // Roc is in bottom (0) or top bin (1) inside a ladder on th ROC map plot
      int binsely = ((clust.mod_on.half==1&&((clust.mod_on.ladder<0&&clust.mod_on.ladder%2==0)||clust.mod_on.ladder%2==1))
      	       ||(clust.mod_on.half==0&&((clust.mod_on.ladder<0 &&((clust.mod_on.ladder%2==-1&&clust.x<80.0)
      								   ||(clust.mod_on.ladder%2==0&&clust.x>=80.0)))
      					 ||(clust.mod_on.ladder>0 &&((clust.mod_on.ladder%2==0&&clust.x<80.0)
      								     ||(clust.mod_on.ladder%2==1&&clust.x>=80.0))))));
      clu_roc_biny = (clust.mod_on.layer * 6 + clust.mod_on.ladder + 4) * 2 + 1 + binsely;
    } else if (clust.mod_on.det==1) {
      // Gives the number of ROCs along ly
      int nrocly = clust.mod_on.module + clust.mod_on.panel;
      for (int i=0; i<nrocly; i++) {
        // ROC number = nrocly - 1 - i for + LX and nrocly + i for -LX.
        int j = (clust.mod_on.disk<0) ? i : nrocly - 1 - i;
        if (clust.y>=(j*52.0)&&clust.y<((j+1)*52.0))
          clu_roc_biny = 6 - nrocly + 2 * i + ((clust.mod_on.blade>0) ? clust.mod_on.blade-1 : clust.mod_on.blade + 12)*12 + 1;
      }
    }
  }

  void init() {
    lumi_totlumi = 0.0;

    traj_det_x = NOVAL_I;
    traj_lay_x = NOVAL_I;
    traj_sdpx = NOVAL_I;
    traj_mod_indexx = NOVAL_I;
    traj_mod_indexy = NOVAL_I;
    traj_mod_x = NOVAL_I;
    traj_mod_y = NOVAL_I;
    traj_mod_p1 = NOVAL_I;
    traj_roc_p1 = NOVAL_I;
    traj_roc_binx = NOVAL_I;
    traj_roc_biny = NOVAL_I;
    traj_run_binx = NOVAL_I; 
    inac = NOVAL_I;
    p1_fid = NOVAL_I;
    p2_fid = NOVAL_I;
    p1_fillsch10 = NOVAL_I;
    p1_fillsch11 = NOVAL_I;
    delay = NOVAL_I;
    p2_secdisk = NOVAL_I;
    p3_layrog = NOVAL_I;

    reset_counters(NOVAL_I);
    
    clu_det_x = NOVAL_I;
    clu_lay_x = NOVAL_I;
    clu_sdpx = NOVAL_I;
    clu_mod_indexx = NOVAL_I;
    clu_mod_indexy = NOVAL_I;
    clu_mod_p1 = NOVAL_I;
    clu_roc_p1 = NOVAL_I;
    clu_roc_binx = NOVAL_I;
    clu_roc_biny = NOVAL_I;

    traj_nrun = 0;

    lumi_runcheck_ = 0;
    lumi_fillcheck_ = 0;
    evt_fillcheck_ = 0;
    traj_evt_runcheck_ = NOVAL_I;
    traj_evt_lscheck_ = NOVAL_I;
    traj_evt_evtcheck_ = NOVAL_I;
    traj_evt_fillcheck_ = 0;

    clu_evt_fillcheck_ = 0;

    zb = 0;
    nvtx = 0;
    federr = 0;
    pt = 0;
    hp = 0;
    nstrip = 0;
    d0 = 0;
    dz = 0;
    pixhit = 0;
    noscan = 0;
    goodmod = 0;
    goodroc = 0;
    lx_fid = 0;
    ly_fid = 0;
    valmis = 0;
    hitsep = 0;

    effcut_all= 0;
    effcut_trig= 0;
    effcut_nvtx= 0;
    effcut_federr= 0;
    effcut_pt= 0;
    effcut_nstrip= 0;
    effcut_d0= 0;
    effcut_dz= 0;
    effcut_d0_dz= 0;
    effcut_scans= 0;
    effcut_ly_fid= 0;
    effcut_lx_fid= 0;
    effcut_lxly_fid= 0;
    effcut_hitsep= 0;
  }

  void reset_counters(int val) {
    // Reset all counters for new event
    for (size_t i=0; i<10; i++) npix_det_[i]=val;
    for (size_t i=0; i<5; i++) for (size_t j=0; j<9; j++)
      for (size_t k=0; k<npix_mod_[i][j].size(); k++) npix_mod_[i][j][k]=val;
    // nclu
    for (size_t i=0; i<10; i++) nclu_det_[i]=0;
    for (size_t i=0; i<5; i++) for (size_t j=0; j<9; j++)
      for (size_t k=0; k<nclu_mod_[i][j].size(); k++) nclu_mod_[i][j][k]=val;
    // New roc counter
    for (size_t i=0; i<8; i++) for (size_t j=0; j<roc_occupancy_list[0][i].size(); j++)
      for (size_t k=0; k<roc_occupancy_list[0][i][j].size(); k++) {
	roc_occupancy_list[0][i][j][k]=val;
	roc_occupancy_list[1][i][j][k]=val;
	for (size_t l=0; l<dcol_occupancy_list[0][i][j][k].size(); l++) {
	  dcol_occupancy_list[0][i][j][k][l]=val;
	  dcol_occupancy_list[1][i][j][k][l]=val;
	}
      }
  }

  void count_npix(const EventData &cluevt, const Cluster &clust) {
    // npix
    npix_det_[0]+=clust.size;
    npix_det_[clu_det_x]+=clust.size;
    npix_det_[clu_lay_x+2]+=clust.size;
    npix_mod_[clu_roc_p1][clu_mod_indexx][clu_mod_indexy]+=clust.size;
    roc_occupancy_list[1][clu_p1_rocid][clu_p2_rocid][clu_p3_rocid]+=clust.size;
    for (int i=0; i<clust.size; i++)
      dcol_occupancy_list[1][clu_p1_rocid][clu_p2_rocid][clu_p3_rocid][int(clust.pix[i][0])/2%26]++;
    // nclu
    nclu_det_[0]++;
    nclu_det_[clu_det_x]++;
    nclu_det_[clu_lay_x+2]++;
    nclu_mod_[clu_roc_p1][clu_mod_indexx][clu_mod_indexy]++;
    roc_occupancy_list[0][clu_p1_rocid][clu_p2_rocid][clu_p3_rocid]++;
    dcol_occupancy_list[0][clu_p1_rocid][clu_p2_rocid][clu_p3_rocid][int(clust.y)/2%26]++;
  }

  void count_runs_fills_lumi(const LumiData &lumi, PostFixes &p) {
    // Manual fill declaration
#if VERSION2 >= 27
    int fill = lumi.fill;
    if (fill==NOVAL_I) {
      fill = (lumi.run>=132596&&lumi.run<=132606) ? 1022
	: (lumi.run>=149181&&lumi.run<=149182) ? 1450
	: (lumi.run>=160431&&lumi.run<=160433) ? 1615
	: (lumi.run>=160577&&lumi.run<=160579) ? 1622
	: (lumi.run>=160808&&lumi.run<=160835) ? 1634
      	: (lumi.run>=165098&&lumi.run<=165104) ? 1783
	: (lumi.run>=167281&&lumi.run<=167284) ? 1883
      	: (lumi.run>=169985&&lumi.run<=170000) ? 1944
      	: (lumi.run>=171875&&lumi.run<=171897) ? 1985
      	: (lumi.run>=172485&&lumi.run<=172620) ? 2000
	: (lumi.run==173692) ? 2040
      	: (lumi.run>=175832&&lumi.run<=175837) ? 2083
	: (lumi.run>=176201&&lumi.run<=176207) ? 2103
	: (lumi.run>=176304&&lumi.run<=176309) ? 2105
	: (lumi.run>=178003&&lumi.run<=178004) ? 2186
	: (lumi.run>=178420&&lumi.run<=178424) ? 2208
	: (lumi.run>=190289&&lumi.run<=190391) ? 2469
	: (lumi.run>=190538&&lumi.run<=190539) ? 2479
	: (lumi.run>=190591&&lumi.run<=190595) ? 2482
	: (lumi.run>=195913&&lumi.run<=195937) ? 2717
	: -1;
    }
#else
    int fill = (lumi.run>=132596&&lumi.run<=132606) ? 1022
      : (lumi.run>=149181&&lumi.run<=149182) ? 1450
      : (lumi.run>=160431&&lumi.run<=160433) ? 1615
      : (lumi.run>=160577&&lumi.run<=160579) ? 1622
      : (lumi.run>=160808&&lumi.run<=160835) ? 1634
      : (lumi.run>=165098&&lumi.run<=165104) ? 1783
      : (lumi.run>=167281&&lumi.run<=167284) ? 1883
      : (lumi.run>=169985&&lumi.run<=170000) ? 1944
      : (lumi.run>=171875&&lumi.run<=171897) ? 1985
      : (lumi.run>=172485&&lumi.run<=172620) ? 2000
      : (lumi.run==173692) ? 2040
      : (lumi.run>=175832&&lumi.run<=175837) ? 2083
      : (lumi.run>=176201&&lumi.run<=176207) ? 2103
      : (lumi.run>=176304&&lumi.run<=176309) ? 2105
      : (lumi.run>=178003&&lumi.run<=178004) ? 2186
      : (lumi.run>=178420&&lumi.run<=178424) ? 2208
      : (lumi.run>=190289&&lumi.run<=190391) ? 2469
      : (lumi.run>=190538&&lumi.run<=190539) ? 2479
      : (lumi.run>=190591&&lumi.run<=190595) ? 2482
      : (lumi.run>=195913&&lumi.run<=195937) ? 2717
      : -1;
#endif
    // Count fills - now works for all version
    if (fill!=lumi_fillcheck_&&lumi_fill_index.count(fill)==0) {
      lumi_runs_in_fill.push_back(std::vector<int>());
      lumi_nfill++;
      lumi_fill_index[fill] = lumi_nfill; // postfix index, -1 for fill index
      std::stringstream ss;
      if (fill==-1) ss<<"_UNDEF";
      else ss<<"_"<<fill;
      p.fill.push_back(ss.str());
      std::string s = ss.str();
      s.erase(0,1);
      lumi_fillname[fill]=s;
      p.Fill.push_back(s);
      p.Fill2.push_back("Fill "+s);
    }
    lumi_fillcheck_ = fill;

    if (lumi.run!=lumi_runcheck_&&lumi_run2.count(lumi.run)==0) {
      // Fill definition !! Very important to keep intact
      filldef[lumi.run] = fill;
      lumi_run.push_back(lumi.run);
      lumi_nrun = lumi_run.size();
      lumi_run2[lumi.run] = lumi_nrun;
      lumi_runs_in_fill[lumi_fill_index[fill]-1].push_back(lumi.run);
#if VERSION2 >= 27
      if (lumi_firstrun.count(fill)==0) {
	lumi_firstrun[fill] = lumi.run;
	lumi_fillstart[fill] = (unsigned int)(lumi.time - lumi.ls*23.3112);
	// std::cout<<"Fill"<<fill<<" elso runja: "<<lumi.run
	// 	 <<" amely ekkor kezdodott: "<<lumi_fillstart[fill]<<std::endl;
      } else if (lumi_firstrun[fill]>lumi.run) {
	lumi_firstrun[fill] = lumi.run;
	lumi_fillstart[fill] = (unsigned int)(lumi.time - lumi.ls*23.3112);
	// std::cout<<"Fill"<<fill<<" elso runja modosult erre: "<<lumi.run
	// 	 <<" amely ekkor kezdodott: "<<lumi_fillstart[fill]<<std::endl;
      }
#else
      if (lumi_firstrun.count(fill)==0) lumi_firstrun[fill] = lumi.run;
      else if (lumi_firstrun[fill]>lumi.run) lumi_firstrun[fill] = lumi.run;
#endif
    }
    lumi_runcheck_ = lumi.run;
  }

  // Accessors
  int npix()      { return npix_det_[0]; }
  int npix_det()  { return npix_det_[traj_det_x]; }
  int npix_lay()  { return npix_det_[traj_lay_x+2]; }
  int npix_lay(int i)  { return npix_det_[i+2]; }
  int npix_mod()  { return npix_mod_[traj_roc_p1][traj_mod_indexx][traj_mod_indexy]; }
  int npix_roc()  { return roc_occupancy_list[1][p1_rocid][p2_rocid][p3_rocid]; }
  int npix_dcol()  { return dcol_occupancy_list[1][p1_rocid][p2_rocid][p3_rocid][dcol_id]; }

  int nclu()      { return nclu_det_[0]; }
  int nclu_det()  { return nclu_det_[traj_det_x]; }
  int nclu_det(int i)  { return nclu_det_[i]; }
  int nclu_lay()  { return nclu_det_[traj_lay_x+2]; }
  int nclu_lay(int i)  { return nclu_det_[i+2]; }
  int nclu_mod()  { return nclu_mod_[traj_roc_p1][traj_mod_indexx][traj_mod_indexy]; }
  int nclu_roc()  { return roc_occupancy_list[0][p1_rocid][p2_rocid][p3_rocid]; }
  int nclu_dcol()  { return dcol_occupancy_list[0][p1_rocid][p2_rocid][p3_rocid][dcol_id]; }

};
