namespace nel {

	//エミッタパラメータ
	struct EmitterParameter {
	public:
		wstring					EName;						//エミッタ名
		CVector					EPositionRange;				//生成位置の幅
		CVector					EInitVelocity;				//初期加速度
		CVector					EInitVelocityRange;			//初期加速度の幅
		CVector					EVelocity;					//加速度の変化量
		CVector					EVelocityRange;				//加速度の幅
		CQuaternion				EInitRotation;				//初期回転量
		CQuaternion				EInitRotationRange;			//初期回転量の幅
		CQuaternion				ERotation;					//回転量の変化量
		CQuaternion				ERotationRange;				//回転量の幅
		unsigned int			ELifeTime;					//生存時間（フレーム単位）
		unsigned int			ELifeTimeRange;				//生存時間の幅
		vector<wstring>			EEGenerationList;			//エミッタ生成リスト
		vector<unsigned int>	EEInterval;					//エミッタ生成間隔
		vector<unsigned int>	EEProduction;				//エミッタ生成量
		vector<wstring>			EPGenerationList;			//パーティクル生成リスト
		vector<unsigned int>	EPInterval;					//パーティクル生成間隔
		vector<unsigned int>	EPProduction;				//パーティクル生成量

		//コンストラクタ

		//引数なしコンストラクタ
		EmitterParameter() :
			EName(L""),
			EPositionRange(CVector()),
			EInitVelocity(CVector()), EInitVelocityRange(CVector()), EVelocity(CVector()), EVelocityRange(CVector()), 
			EInitRotation(CQuaternion()), EInitRotationRange(CQuaternion()), ERotation(CQuaternion()), ERotationRange(CQuaternion()), 
			ELifeTime(0), ELifeTimeRange(0) {}

		//パラメータ値を返します
		EmitterParameter& GetParameter() { return *this; }
	};
}