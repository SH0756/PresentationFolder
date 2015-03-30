namespace nel {

	//---------------------------------------------------------------------------------------------------------------------------
	//パーティクルファイルの操作クラス
	class CParticleFile : public ParticleParameter {
	public:
		wstring ParticleFileName;			//読み込んだパーティクルファイル名

		//引数なしコンストラクタ
		CParticleFile() : ParticleFileName(NULL), ParticleParameter() {}

		//filename からパラメータ値を読み込みます
		CParticleFile(wstring filename) : ParticleFileName(filename), ParticleParameter() {
			ReadParticleFile(filename);
		}

		//ファイルからパーティクルのパラメータ値を読み込みます（.particle形式）
		void ReadParticleFile(wstring filename);
	};

	//パーティクルファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateParticleFile(wstring filename);


	//----------------------------------------------------------------------------------------------------------------------------
	//エミッタファイルの操作クラス
	class CEmitterFile : public EmitterParameter {
	public:
		wstring EmitterFileName;			//読み込んだエミッタファイル名

		//引数なしコンストラクタ
		CEmitterFile() : EmitterFileName(NULL), EmitterParameter() {}

		//filename からパラメータ値を読み込みます
		CEmitterFile(wstring filename) : EmitterFileName(filename), EmitterParameter() {
			ReadEmitterFile(filename);
		}

		//ファイルからエミッタのパラメータ値を読み込みます（.emitter形式）
		void ReadEmitterFile(wstring filename);
	};

	//エミッタファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateEmitterFile(wstring filename);
}
