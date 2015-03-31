namespace nel {

	//�p�[�e�B�N���p�����[�^
	struct ParticleParameter{
	public:
		wstring			PName;						//�p�[�e�B�N����
		wstring			PTextureName;				//�e�N�X�`����
		wstring			PModelName;					//���f�����i.x�`���j
		CVector			PInitScale;					//�g��k�����̏����l
		CVector			PInitScaleRange;				//�g��k�����̏����l�̕�
		CVector			PEndScale;					//�g��k�����̏I���l
		CVector			PScale;						//�g��k�����̕ω���
		CColor			PInitColor;					//�F�̏����l
		CColor			PInitColorRange;				//�F�̏����l�̕�
		CColor			PEndColor;					//�F�̏I���l
		CColor			PColor;						//�F�̕ω���
		CColor			PInitSpecularColor;			//�n�C���C�g�F�̏����l
		CColor			PInitSpecularColorRange;		//�n�C���C�g�F�̏����l�̕�
		CColor			PEndSpecularColor;			//�n�C���C�g�F�̏I���l
		CColor			PSpecularColor;				//�n�C���C�g�F�̕ω���
		CColor			PInitEmissiveColor;			//���Ȕ����F�̏����l
		CColor			PInitEmissiveColorRange;		//���Ȕ����F�̏����l�̕�
		CColor			PEndEmissiveColor;			//���Ȕ����F�̏I���l
		CColor			PEmissiveColor;				//���Ȕ����F�̕ω���
		CColor			PInitRimColor;				//�������C�g�F�̏����l
		CColor			PInitRimColorRange;			//�������C�g�F�̏����l�̕�
		CColor			PEndRimColor;				//�������C�g�F�̏I���l
		CColor			PRimColor;					//�������C�g�F�̕ω���
		CVector			PPositionRange;				//�����ʒu�̕�
		CVector			PInitVelocity;				//���������x
		CVector			PInitVelocityRange;			//���������x�̕�
		CVector			PVelocity;					//�����x�̕ω���
		CVector			PVelocityRange;				//�����x�̕�
		CQuaternion		PInitRotation;				//������]��
		CQuaternion		PInitRotationRange;			//������]�ʂ̕�
		CQuaternion		PRotation;					//��]�ʂ̕ω���
		CQuaternion		PRotationRange;				//��]�ʂ̕�
		bool			PUseGravity;					//�d�͂̉e�����󂯂邩�ǂ���
		float			PGravity;					//�d�͂̋���
		unsigned int	PLifeTime;					//�������ԁi�t���[���P�ʁj
		unsigned int	PLifeTimeRange;				//�������Ԃ̕�
		bool			PBillboard;					//�r���{�[�h�i�f�t�H���g�� true�j
		bool			PShadowCasting;				//���̕��͉̂e�𗎂Ƃ��i�f�t�H���g�� true�j
		bool			PShadowCasted;				//���̕��͉̂e��������i�f�t�H���g�� true�j

		//�R���X�g���N�^

		//�����Ȃ��R���X�g���N�^
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

		//�p�����[�^�l��Ԃ��܂�
		ParticleParameter& GetParameter() { return *this; }
	};
}
