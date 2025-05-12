namespace lifetimes
{
	class Entity {};

	class ScopedPtr
	{
	private:
		Entity* m_Ptr;
	public:
		ScopedPtr(Entity* ptr) : m_Ptr(ptr)
		{
			// Initialize ptr to m_Ptr
		}
		~ScopedPtr()
		{
			delete m_Ptr;
		}
	};
}