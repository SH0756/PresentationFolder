namespace nel {

	//������̊g��-------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------------
	//�����񑊌ݕϊ��Q�ƃT�C�g
	//https://gist.github.com/TAMAGO-JP/31f0030d26b321a9548e

	// �V���O���o�C�g�A�}���`�o�C�g�����񉻊֐�
	inline string TWStringToString(const wstring& arg_wstr)
	{
		// ������
		size_t length = arg_wstr.size();

		// �ϊ��㕶����
		size_t convLength;

		// ���̎󂯎M��p�Ӂi�������~2�����\���ł��傤�j
		char *c = (char*)malloc(sizeof(char)* length * 2);

		// �ϊ�
		wcstombs_s(&convLength, c, sizeof(char)* length * 2, arg_wstr.c_str(), length * 2);

		// �Ԃ�l�֕ۑ�
		string result(c);

		// ���̎󂯎M��j��
		free(c);

		return result;
	};

	// ���C�h�����񉻊֐�
	inline wstring StringToWString(const string& arg_str)
	{
		// ������
		size_t length = arg_str.size();

		// �ϊ��㕶����
		size_t convLength;

		// ���̎󂯎M��p��
		wchar_t *wc = (wchar_t*)malloc(sizeof(wchar_t)* (length + 2));

		// �ϊ�
		mbstowcs_s(&convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE);

		// �Ԃ�l�֕ۑ�
		wstring str(wc);

		// ���̎󂯎M��j��
		free(wc);

		return str;
	};
	//---------------------------------------------------------------------------------------------------------------------

	// string ���� bool �ւ̕ϊ�
	inline bool StringToBool(const string& str) {
		if (str == "false") return false;
		else { return true; }
	}

	// string ���� int �ւ̕ϊ�
	inline int StringToInt(const string& str) {
		stringstream ss(str);
		int result;
		ss >> result;
		return result;
	}

	// string ���� float �ւ̕ϊ�
	inline float StringToFloat(const string& str) {
		stringstream ss(str);
		float result;
		ss >> result;
		return result;
	}

	//������̕���
	// str �� delim �ŋ�؂��āA result �ɓ���܂�
	inline void Split(const string& str, char delim, vector<string>& result) {
		stringstream ss(str);
		string s;
		while (getline(ss, s, delim)) {
			result.push_back(s);
		}
	}

	// project �ւ̃p�X
	//inline wstring GetExePath() { return L"C:/Users/vantan/Desktop/�Q�[������/Games/EffectSample/ParticleFile/project213_ParticleFile/Main/"; }



	//HigPen�̊g��----------------------------------------------------------------------------------------------------------------------------------

	inline CVector StringToCVector(const string& vec) {
		vector<string> results;
		vector<float> resultf;

		nel:: Split(vec, ',', results);

		for (int i = 0; i < 3; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CVector(resultf[0], resultf[1], resultf[2]);
	}

	inline CColor StringToCColor(const string& color) {
		vector<string> results;
		vector<float> resultf;

		nel::Split(color, ',', results);

		for (int i = 0; i < 4; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CColor(resultf[0], resultf[1], resultf[2], resultf[3]);
	}

	inline CQuaternion StringToCQuaternion(const string& rotation) {
		vector<string> results;
		vector<float> resultf;

		nel::Split(rotation, ',', results);

		for (int i = 0; i < 4; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CQuaternion(Normalize(CVector(resultf[0], resultf[1], resultf[2])), resultf[3]);
	}

}