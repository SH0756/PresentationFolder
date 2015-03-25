namespace nel {

	//パーティクルパラメータ
	struct ParticleParameter{
	public:
		wstring			Name;						//パーティクル名
		wstring			TextureName;				//テクスチャ名
		wstring			ModelName;					//モデル名（.x形式）
		CVector			InitScale;					//拡大縮小率の初期値
		CVector			InitScaleRange;				//拡大縮小率の初期値の幅
		CVector			EndScale;					//拡大縮小率の終了値
		CVector			Scale;						//拡大縮小率の変化量
		CColor			InitColor;					//色の初期値
		CColor			InitColorRange;				//色の初期値の幅
		CColor			EndColor;					//色の終了値
		CColor			Color;						//色の変化量
		CColor			InitSpecularColor;			//ハイライト色の初期値
		CColor			InitSpecularColorRange;		//ハイライト色の初期値の幅
		CColor			EndSpecularColor;			//ハイライト色の終了値
		CColor			SpecularColor;				//ハイライト色の変化量
		CColor			InitEmissiveColor;			//自己発光色の初期値
		CColor			InitEmissiveColorRange;		//自己発光色の初期値の幅
		CColor			EndEmissiveColor;			//自己発光色の終了値
		CColor			EmissiveColor;				//自己発光色の変化量
		CColor			InitRimColor;				//リムライト色の初期値
		CColor			InitRimColorRange;			//リムライト色の初期値の幅
		CColor			EndRimColor;				//リムライト色の終了値
		CColor			RimColor;					//リムライト色の変化量
		CVector			PositionRange;				//生成位置の幅
		CVector			InitVelocity;				//初期加速度
		CVector			InitVelocityRange;			//初期加速度の幅
		CVector			Velocity;					//加速度の変化量
		CVector			VelocityRange;				//加速度の幅
		CQuaternion		InitRotation;				//初期回転量
		CQuaternion		InitRotationRange;			//初期回転量の幅
		CQuaternion		Rotation;					//回転量の変化量
		CQuaternion		RotationRange;				//回転量の幅
		bool			UseGravity;					//重力の影響を受けるかどうか
		float			Gravity;					//重力の強さ
		unsigned int	LifeTime;					//生存時間（フレーム単位）
		unsigned int	LifeTimeRange;				//生存時間の幅
		bool			Billboard;					//ビルボード（デフォルトは true）
		bool			ShadowCasting;				//この物体は影を落とす（デフォルトは true）
		bool			ShadowCasted;				//この物体は影が落ちる（デフォルトは true）

		//コンストラクタ

		//引数なしコンストラクタ
		ParticleParameter() :
			Name(L""), TextureName(L""), ModelName(L""),
			InitScale(CVector()), InitScaleRange(CVector()), EndScale(CVector()), Scale(CVector()),
			InitColor(CColor()), InitColorRange(CColor()), EndColor(CColor()), Color(CColor()),
			InitSpecularColor(CColor()), InitSpecularColorRange(CColor()), EndSpecularColor(CColor()), SpecularColor(CColor()),
			InitEmissiveColor(CColor()), InitEmissiveColorRange(CColor()), EndEmissiveColor(CColor()), EmissiveColor(CColor()),
			InitRimColor(CColor()), InitRimColorRange(CColor()), EndRimColor(CColor()), RimColor(CColor()),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()),
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()),
			UseGravity(false), Gravity(0.0001f),
			LifeTime(0), LifeTimeRange(0),
			Billboard(true), ShadowCasting(true), ShadowCasted(true) {}

		//変化量を求める
		void Movement() {
			if (LifeTime < LifeTimeRange) LifeTimeRange = LifeTime - 1;
			LifeTime = (unsigned int)(LifeTime + LifeTimeRange * Random(-1, 1));
			Scale = (EndScale - InitScale) / (float)LifeTime;
			Color = (EndColor - InitColor) / (float)LifeTime;
			SpecularColor = (EndSpecularColor - InitSpecularColor) / (float)LifeTime;
			EmissiveColor = (EndEmissiveColor - InitEmissiveColor) / (float)LifeTime;
			RimColor = (EndRimColor - InitRimColor) / (float)LifeTime;
			Velocity += VelocityRange * Random(-1, 1);
			Rotation += RotationRange * Random(-1, 1);
		}

		//パラメータ値を返します
		ParticleParameter& GetParameter() { return *this; }
	};
}
