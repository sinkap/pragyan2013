#include <vector>
#include <iostream>
#include <fstream> 
#define LINE 'L'
#define HIST 'H'
#define SCATTER 'S'

using namespace std; 

class Grapher {


	public:


		Grapher();
		void plot(char type, const vector<float>& vec_x, string title); 
		void plot(char type, vector<float>& vec_x, vector<float>& vec_y, string title); 
		void show(); 

	private:
		string _backend; 
		string _file; 
		ofstream _fh; 

}; 


Grapher::Grapher() : _backend("/Users/kapileshwarsingh/randomWalkBias/graph.py"), _file("/tmp/graph.current") {

	_fh.open(_file.c_str(), ios::trunc | ios::out); 


}


void Grapher::plot(char type, const vector<float>& vec_x, string keyvals) {


	switch(type) {

		case LINE:
			_fh << "line:" ; 

			for (int i = 0; i < vec_x.size() ; ++i) {

				if (i == (vec_x.size() - 1))
					_fh << vec_x[i]; 
				else
					_fh << vec_x[i] << ", "; 

			}

			_fh << ":" << keyvals; 
			_fh << endl; 
			return; 
		
		case HIST:	

                        _fh << "hist:" ;

                        for (int i = 0; i < vec_x.size() ; ++i) {

                                if (i == (vec_x.size() - 1))
                                        _fh << vec_x[i];
                                else
                                        _fh << vec_x[i] << ", ";

                        }

                        _fh << ":" << keyvals << endl;
                        return;

		


		default:
			cout << "Graph type not supported" << endl;
			exit(1); 
	
	}	
}	
		

void Grapher::plot(char type, vector<float>& vec_x, vector<float>& vec_y, string keyvals) {



	switch(type) {

		case SCATTER:
	                
			_fh << "scatter:" ;

                        for (int i = 0; i < vec_x.size() ; ++i) {

                                if (i == (vec_x.size() - 1))
                                        _fh << vec_x[i];
                                else
                                        _fh << vec_x[i] << ", ";

                        }

			_fh << ":" ; 

			for (int i = 0; i < vec_y.size() ; ++i) {

                                if (i == (vec_y.size() - 1))
                                        _fh << vec_y[i];
                                else
                                        _fh << vec_y[i] << ", ";

                        }

			_fh << ":" << keyvals << endl ; 
			
			return ; 

		default:
			cout << "Invalid Graph Type" << endl ; 
			exit(1); 

	}
}

void Grapher::show() {

	_fh.close(); 
		
	system(string(_backend + string(" ") + _file + string(" &")).c_str()); 

}


