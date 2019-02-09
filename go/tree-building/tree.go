package tree

import (
	"errors"
	"sort"
)

type Record struct {
	ID     int
	Parent int
}

type Node struct {
	ID       int
	Children []*Node
}

func neighbors(adjacencyList map[int][]int, current int) []int {
	res, _ := adjacencyList[current]
	sort.Ints(res)
	return res
}

// Build constructs a Node that represents a tree of records
func Build(records []Record) (*Node, error) {
	// Check that there are a valid amount of items
	count := len(records)
	if count == 0 {
		return nil, nil
	}

	adjacencyList := make(map[int][]int)
	for _, rec := range records {
		adjacencyList[rec.Parent] = append(adjacencyList[rec.Parent], rec.ID)
	}

	// Check that the root node exists
	rootCount := 0
	for _, v := range adjacencyList[0] {
		if v == 0 {
			rootCount += 1
		}
	}

	if rootCount == 0 {
		return nil, errors.New("No root node exists")
	} else if rootCount > 1 {
		return nil, errors.New("Duplicate root nodes exist")
	}

	// Run BFS from root node to leaf nodes
	result := &Node{ID: 0}
	queue := []*Node{result}
	visited := make(map[int]bool)
	for i := 0; i < len(records); i++ {
		visited[i] = false
	}
	var curNode *Node
	var nxtNode *Node

	for len(queue) > 0 {
		curNode, queue = queue[0], queue[1:]

		// Check whether a cycle exists
		if val, ok := visited[curNode.ID]; ok && val {
			return nil, errors.New("Cycle detected in graph")
		}

		// Check whether a higher identifier was found
		for _, v := range neighbors(adjacencyList, curNode.ID) {
			if v > curNode.ID {
				nxtNode = &Node{ID: v}
				curNode.Children = append(curNode.Children, nxtNode)
				queue = append(queue, nxtNode)
			} else if v < curNode.ID {
				return nil, errors.New("Higher ID is an invalid parent")
			}
		}

		visited[curNode.ID] = true
	}

	for _, v := range visited {
		if !v {
			return nil, errors.New("The records are non-contiguous")
		}
	}

	return result, nil
}
