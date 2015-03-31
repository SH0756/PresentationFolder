namespace nel {

	//パーティクルパラメータ
	struct ParticleParameter{
	public:
		wstring			PName;						//パーティクル名
		wstring			PTextureName;				//テクスチャ名
		wstring			PModelName;					//モデル名（.x形式）
		CVector			PInitScale;					//拡大縮小率の初期値
		CVector			PInitScaleRange;				//拡大縮小率の初期値の幅
		CVector			PEndScale;					//拡大縮小率の終了値
		CVector			PScale;						//拡大縮小率の変化量
		CColor			PInitColor;					//色の初期値
		CColor			PInitColorRange;				//色の初期値の幅
		CColor			PEndColor;					//色の終了値
		CColor			PColor;						//色の変化量
		CColor			PInitSpecularColor;			//ハイライト色の初期値
		CColor			PInitSpecularColorRange;		//ハイライト色の初期値の幅
		CColor			PEndSpecularColor;			//ハイライト色の終了値
		CColor			PSpecularColor;				//ハイライト色の変化量
		CColor			PInitEmissiveColor;			//自己発光色の初期値
		CColor			PInitEmissiveColorRange;		//自己発光色の初期値の幅
		CColor			PEndEmissiveColor;			//自己発光色の終了値
		CColor			PEmissiveColor;				//自己発光色の変化量
		CColor			PInitRimColor;				//リムライト色の初期値
		CColor			PInitRimColorRange;			//リムライト色の初期値の幅
		CColor			PEndRimColor;				//リムライト色の終了値
		CColor			PRimColor;					//リムライト色の変化量
		CVector			PPositionRange;				//生成位置の幅
		CVector			PInitVelocity;				//初期加速度
		CVector			PInitVelocityRange;			//初期加速度の幅
		CVector			PVelocity;					//加速度の変化量
		CVector			PVelocityRange;				//加速度の幅
		CQuaternion		PInitRotation;				//初期回転量
		CQuaternion		PInitRotationRange;			//初期回転量の幅
		CQuaternion		PRotation;					//回転量の変化量
		CQuaternion		PRotationRange;				//回転量の幅
		bool			PUseGravity;					//重力の影響を受けるかどうか
		float			PGravity;					//重力の強さ
		unsigned int	PLifeTime;					//生存時間（フレーム単位）
		unsigned int	PLifeTimeRange;				//生存時間の幅
		bool			PBillboard;					//ビルボード（デフォルトは true）
		bool			PShadowCasting;				//この物体は影を落とす（デフォルトは true）
		bool			PShadowCasted;				//この物体は影が落ちる（デフォルトは true）

		//コンストラクタ

		//引数なしコンストラクタ
		ParticleParameter() :
			PName(L""), PTextureName(L""), PModelName(L""),
			PInitScale(CVector()), PInitScaleRange(CVector()), PEndScale(CVector()), PScale(CVector()),
			PInitColor(CColor()), PInitColorRange(CColor()), PEndColor(CColor()), PColor(CColor()),
			PInitSpecularColor(CColor()), PInitSpecularColorRange(CColor()), PEndSpecularColor(CColor()), PSpecularColor(CColor()),
			PInitEmissiveColor(CColor()), PInitEmissiveColorRange(CColor()), PEndEmissiveColor(CColor()), PEmissiveColor(CColor()),
			PInitRimColor(CColor()), PInitRimColorRange(CColor()), PEndRimColor(CColor()), PRimColor(CColor()),
			PPositionRange(CVector()),
			PInitVelocity(CVector()), PInitVelocityRange(CVector()), PVelocity(CVector()), PVelocityRange(CVector()),
			PInitRotation(CQuaternion()), PInitRotationRange(CQuaternion()), PRotation(CQuaternion()), PRotationRange(CQuaternion()),
			PUseGravity(false), PGravity(0.0001f),
			PLifeTime(0), PLifeTimeRange(0),
			PBillboard(true), PShadowCasting(true), PShadowCasted(true) {}

		//パラメータ値を返します
		ParticleParameter& GetParameter() { return *this; }
	};
}
