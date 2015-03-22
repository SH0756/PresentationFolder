namespace nel {

	//パーティクルファイルの操作-----------------------------------------------------------------------------------------
	class CParticleFile {
	public:
		ParticleParameter* Param;

		//引数なしコンストラクタ
		CParticleFile() : Param(NULL) {}

		//filename からパラメータ値を読み込みます
		CParticleFile(wstring filename) {
			Param = new ParticleParameter;
			ReadParticleFile(filename, *Param);
		}

		//ファイルからパーティクルのパラメータ値を読み込みます（.particle形式）
		void ReadParticleFile(wstring filename, ParticleParameter& param);

		~CParticleFile() { delete Param; }
	};

	//パーティクルファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateParticleFile(wstring filename);


	//エミッタファイルの操作-----------------------------------------------------------------------------------------------
	class CEmitterFile {
	public:
		EmitterParameter* Param;

		//引数なしコンストラクタ
		CEmitterFile() : Param(NULL) {}

		//filename からパラメータ値を読み込みます
		CEmitterFile(wstring filename) {
			Param = new EmitterParameter;
			ReadEmitterFile(filename, *Param);
		}

		//ファイルからエミッタのパラメータ値を読み込みます（.emitter形式）
		void ReadEmitterFile(wstring filename, EmitterParameter& param);

		~CEmitterFile() { delete Param; }
	};

	//エミッタファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateEmitterFile(wstring filename);
}
