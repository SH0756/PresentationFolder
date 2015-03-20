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
		CColor			InitEmissiveColor;			//���Ȕ����F�̏����l
		CColor			InitEmissiveColorRange;		//���Ȕ����F�̏����l�̕�
		CColor			EndEmissiveColor;			//���Ȕ����F�̏I���l
		CColor			EmissiveColor;				//���Ȕ����F�̕ω���
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

		//�R���X�g���N�^

		//�����Ȃ��R���X�g���N�^
		ParticleParameter() :
			Name(L""), TextureName(L""), ModelName(L""),
			InitScale(CVector()), InitScaleRange(CVector()), EndScale(CVector()), Scale(CVector()),
			InitColor(CColor()), InitColorRange(CColor()), EndColor(CColor()), Color(CColor()),
			InitEmissiveColor(CColor()), InitEmissiveColorRange(CColor()), EndEmissiveColor(CColor()), EmissiveColor(CColor()),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()),
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()),
			UseGravity(false), Gravity(0.0001f),
			LifeTime(0), LifeTimeRange(0),
			Billboard(true) {}

		ParticleParameter& operator*(float n) {
			InitScale *= n;
			InitScaleRange *= n;
			EndScale *= n;
			Scale *= n;
			PositionRange *= n;
			InitVelocity *= n;
			InitVelocityRange *= n;
			Velocity *= n;
			VelocityRange *= n;
			Gravity *= n;
			LifeTime = (unsigned int)(LifeTime * n);
			LifeTimeRange = (unsigned int)(LifeTimeRange * n);

			return *this;
		}
	};
}
