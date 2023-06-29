/*****************************************************************************
The Dark Mod GPL Source Code

This file is part of the The Dark Mod Source Code, originally based
on the Doom 3 GPL Source Code as published in 2011.

The Dark Mod Source Code is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the License,
or (at your option) any later version. For details, see LICENSE.TXT.

Project: The Dark Mod (http://www.thedarkmod.com/)

******************************************************************************/

#ifndef __FORCE_H__
#define __FORCE_H__

/*
===============================================================================

	Force base class

	A force object applies a force to a physics object.

===============================================================================
*/

class idEntity;
class idPhysics;

class idForce : public idClass {

public:
	CLASS_PROTOTYPE( idForce );

						idForce( void );
	virtual				~idForce( void );
	static void			DeletePhysics( const idPhysics *phys );
	static void			ClearForceList( void );

public: // common force interface
						// evaluate the force up to the given time
	virtual void		Evaluate( int time );
						// removes any pointers to the physics object
	virtual void		RemovePhysics( const idPhysics *phys );

private:

	static idList<idForce*> forceList;
};


typedef enum {
	fitNone = 0,
	fitForce,			// generated by idForce::Evaluate
	fitPhysics,			// generated by idPhysics::Evaluate
} forceIdType_t;

// stgatilov #5992: each call to ApplyForce is accompanied with such identifier
struct idForceApplicationId {
	int type;
	union {
		const void *ptr;
		const idForce *force;
		const idPhysics *physics;
	};

	ID_FORCE_INLINE idForceApplicationId() : type(fitNone), ptr(nullptr) {}
	ID_FORCE_INLINE explicit idForceApplicationId(int type, const void *ptr) : type(type), ptr(ptr) {}
	ID_FORCE_INLINE idForceApplicationId(const idForce *force) : type(fitForce), force(force) {}
	ID_FORCE_INLINE idForceApplicationId(const idPhysics *physics) : type(fitPhysics), physics(physics) {}

	ID_FORCE_INLINE bool Same(const idForceApplicationId &other) const {
		return type == other.type && ptr == other.ptr;
	}
};

// stgatilov #5992: one force application
// stores identifier explaining what causes this force
struct idForceApplication {
	idForceApplicationId id;		// identifier of this application
	idVec3 force;					// external force relative to center of mass
	idVec3 point;					// point where the externalForce is being applied at

	void Save(idSaveGame *savefile) const;
	void Restore(idRestoreGame *savefile);
};

// stgatilov #5992: list of individual force applications on a physics objects
// allows to avoid duplicate application, and even support intra-gametic force updates
class idForceApplicationList : private idList<idForceApplication> {
public:
	idForceApplicationList() : idList<idForceApplication>(1) {}

	// adds new force application, or overrides existing one if ID matches
	void Add(const idVec3 &point, const idVec3 &force, const idForceApplicationId &id);

	// compute total force and torque around specified center
	void ComputeTotal(const idVec3 &center, idVec3 *force, idVec3 *torque, idVec3 *point = nullptr) const;

	using idList<idForceApplication>::Clear;

	void Save(idSaveGame *savefile) const;
	void Restore(idRestoreGame *savefile);
};

#endif /* !__FORCE_H__ */
