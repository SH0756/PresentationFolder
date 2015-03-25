namespace nel {

	//�p�[�e�B�N���p�����[�^
	struct ParticleParameter{
	public:
		wstring			Name;						//�p�[�e�B�N����
		wstring			TextureName;				//�e�N�X�`����
		wstring			ModelName;					//���f�����i.x�`���j
		CVector			InitScale;					//�g��k�����̏����l
		CVector			InitScaleRange;				//�g��k�����̏����l�̕�
		CVector			EndScale;					//�g��k�����̏I���l
		CVector			Scale;						//�g��k�����̕ω���
		CColor			InitColor;					//�F�̏����l
		CColor			InitColorRange;				//�F�̏����l�̕�
		CColor			EndColor;					//�F�̏I���l
		CColor			Color;						//�F�̕ω���
		CColor			InitSpecularColor;			//�n�C���C�g�F�̏����l
		CColor			InitSpecularColorRange;		//�n�C���C�g�F�̏����l�̕�
		CColor			EndSpecularColor;			//�n�C���C�g�F�̏I���l
		CColor			SpecularColor;				//�n�C���C�g�F�̕ω���
		CColor			InitEmissiveColor;			//���Ȕ����F�̏����l
		CColor			InitEmissiveColorRange;		//���Ȕ����F�̏����l�̕�
		CColor			EndEmissiveColor;			//���Ȕ����F�̏I���l
		CColor			EmissiveColor;				//���Ȕ����F�̕ω���
		CColor			InitRimColor;				//�������C�g�F�̏����l
		CColor			InitRimColorRange;			//�������C�g�F�̏����l�̕�
		CColor			EndRimColor;				//�������C�g�F�̏I���l
		CColor			RimColor;					//�������C�g�F�̕ω���
		CVector			PositionRange;				//�����ʒu�̕�
		CVector			InitVelocity;				//���������x
		CVector			InitVelocityRange;			//���������x�̕�
		CVector			Velocity;					//�����x�̕ω���
		CVector			VelocityRange;				//�����x�̕�
		CQuaternion		InitRotation;				//������]��
		CQuaternion		InitRotationRange;			//������]�ʂ̕�
		CQuaternion		Rotation;					//��]�ʂ̕ω���
		CQuaternion		RotationRange;				//��]�ʂ̕�
		bool			UseGravity;					//�d�͂̉e�����󂯂邩�ǂ���
		float			Gravity;					//�d�͂̋���
		unsigned int	LifeTime;					//�������ԁi�t���[���P�ʁj
		unsigned int	LifeTimeRange;				//�������Ԃ̕�
		bool			Billboard;					//�r���{�[�h�i�f�t�H���g�� true�j
		bool			ShadowCasting;				//���̕��͉̂e�𗎂Ƃ��i�f�t�H���g�� true�j
		bool			ShadowCasted;				//���̕��͉̂e��������i�f�t�H���g�� true�j

		//�R���X�g���N�^

		//�����Ȃ��R���X�g���N�^
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

		//�ω��ʂ����߂�
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

		//�p�����[�^�l��Ԃ��܂�
		ParticleParameter& GetParameter() { return *this; }
	};
}
