#ifndef OBJECTLOADER_H_
#define OBJECTLOADER_H_

struct Object {
  vector<vector<float>> vecv;
  vector<vector<float>> vecn;
  vector<vector<unsigned>> vecf;
};

Object* loadInput(char * filename){
  vector<vector<float>> vecv;
  vector<vector<float>> vecn;
  vector<vector<unsigned>> vecf;
  string line;
  ifstream myfile(filename);
  if (myfile.is_open()){
    while ( getline (myfile,line) ){

        stringstream ss(line);
        float v[3];
	    vector<float> vec;
	    string s;
	    ss >> s;
	    //if (s=="g") cout << line <<endl;

	    if (s == "v") {
	      ss >> v[0] >> v[1] >> v[2];
	      vec.push_back(v[0]);
	      vec.push_back(v[1]);
	      vec.push_back(v[2]);
	      vecv.push_back(vec);
	    } else if (s == "vn") {
	      ss >> v[0] >> v[1] >> v[2];
	      vec.push_back(v[0]);
	      vec.push_back(v[1]);
	      vec.push_back(v[2]);
	      vecn.push_back(vec);
	    } else if (s == "f") {
	      vector<unsigned> faces;

	      string abc;
	      string def;
	      string ghi;

	      ss >> abc >> def >> ghi;
	      string faceIndices = abc + " " + def + " " + ghi;

	      replace(faceIndices.begin(), faceIndices.end(), '/', ' ');
	      stringstream ssFaces(faceIndices);
	      unsigned n;

	      while (ssFaces >> n) {
	        faces.push_back(n);
	      }
	      vecf.push_back(faces);
	  	}
	}
  }
  myfile.close();
  Object* obj = new Object();
  obj->vecv = vecv;
  obj->vecn = vecn;
  obj->vecf = vecf;
  return obj;
}

#endif
