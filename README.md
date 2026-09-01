# UnrealVoxelSim.Simulation.Api

Engine-independent contracts for deterministic fixed-step simulation. `IStepParticipant` is the single lifecycle
contract used by implementation systems. Composition supplies an explicitly ordered participant sequence to an
`ITickPipeline`; consumers advance it through `IStepper` or `IPacer`.

The API contains no game-domain command stamps, decision phases, or module-specific updater contracts.
