public
class BinaryTreeWithLock
{
private
    class BinaryTreeNode
    {
        int val;
        boolean locked = false;
        BinaryTreeNode parent;
        BinaryTreeNode leftChild;
        BinaryTreeNode rightChild;
        int lockedDescendantCount = 0;
    }

    public boolean
    is_locked(BinaryTreeNode node)
    {
        return node.locked;
    }
public
    boolean lock(BinaryTreeNode node)
    {
        if (is_locked(node))
        {
            return true;
        }
        if (!canLockOrUnlock(node))
        {
            return false;
        }
        node.locked = true;
        BinaryTreeNode parentNode = node.parent;
        while (parentNode != null)
        {
            parentNode.lockedDescendantCount += 1;
            parentNode = parentNode.parent;
        }
        return true;
    }
public
    boolean unlock(BinaryTreeNode node)
    {
        if (!is_locked(node))
        {
            return true;
        }
        if (!canLockOrUnlock(node))
        {
            return false;
        }
        node.locked = false;
        BinaryTreeNode parentNode = node.parent;
        while (parentNode != null)
        {
            parentNode.lockedDescendantCount -= 1;
            parentNode = parentNode.parent;
        }
        return true;
    }
private
    boolean canLockOrUnlock(BinaryTreeNode node)
    {
        if (node.lockedDescendantCount > 0)
        {
            return false;
        }
        BinaryTreeNode parentNode = node.parent;
        while (parentNode != null)
        {
            if (parentNode.locked)
            {
                return false;
            }
            parentNode = parentNode.parent;
        }
        return true;
    }
}