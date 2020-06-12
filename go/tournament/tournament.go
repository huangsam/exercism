package tournament

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"sort"
	"strings"
)

type teamRecord struct {
	name                        string
	matches, wins, ties, losses int
}

func newTeamRecord(name string) teamRecord {
	return teamRecord{name: name}
}

func (r teamRecord) points() int { return r.wins*3 + r.ties }
func (r teamRecord) row() string {
	return fmt.Sprintf(
		"%-30s | %2d | %2d | %2d | %2d | %2d\n",
		r.name,
		r.matches,
		r.wins,
		r.ties,
		r.losses,
		r.points(),
	)
}

func header() string {
	return fmt.Sprintf(
		"%-30s | %2s | %2s | %2s | %2s | %2s\n",
		"Team",
		"MP",
		"W",
		"D",
		"L",
		"P",
	)
}

type teamRecords []teamRecord

func (rs teamRecords) Len() int      { return len(rs) }
func (rs teamRecords) Swap(i, j int) { rs[i], rs[j] = rs[j], rs[i] }
func (rs teamRecords) Less(i, j int) bool {
	if rs[i].points() == rs[j].points() {
		return rs[i].name < rs[j].name
	}
	return rs[i].points() > rs[j].points()
}

// Tally reads game from Reader and writes tally to Writer
func Tally(input io.Reader, output io.Writer) error {
	scanner := bufio.NewScanner(input)
	scoreBoard := make(map[string]*teamRecord)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" || text[0] == '#' {
			continue
		}
		tokens := strings.Split(text, ";")
		if len(tokens) != 3 {
			return errors.New("invalid tokens")
		}
		teamA, teamB, outcome := tokens[0], tokens[1], tokens[2]
		if _, ok := scoreBoard[teamA]; !ok {
			scoreBoard[teamA] = &teamRecord{name: teamA}
		}
		if _, ok := scoreBoard[teamB]; !ok {
			scoreBoard[teamB] = &teamRecord{name: teamB}
		}
		recordA := scoreBoard[teamA]
		recordB := scoreBoard[teamB]
		recordA.matches++
		recordB.matches++
		switch outcome {
		case "win":
			recordA.wins++
			recordB.losses++
			break
		case "loss":
			recordA.losses++
			recordB.wins++
			break
		case "draw":
			recordA.ties++
			recordB.ties++
			break
		default:
			return errors.New("invalid outcome")
		}
	}
	var records teamRecords
	for _, record := range scoreBoard {
		records = append(records, *record)
	}
	sort.Sort(records)
	fmt.Fprintf(output, header())
	for _, record := range records {
		fmt.Fprintf(output, record.row())
	}
	return nil
}
